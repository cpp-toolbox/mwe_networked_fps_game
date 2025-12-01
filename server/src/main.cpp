#include "sound/sound_types/sound_types.hpp"
#include "system_logic/reconciliation_types/reconciliation_types.hpp"
#include "utility/logger/logger.hpp"
#include "utility/temporal_binary_switch/temporal_binary_switch.hpp"
#include "utility/fixed_frequency_loop/fixed_frequency_loop.hpp"
#include "utility/config_file_parser/config_file_parser.hpp"
#include "utility/jolt_meta_types/jolt_meta_types.hpp"
#include "utility/periodic_signal/periodic_signal.hpp"
#include "utility/glm_meta_types/glm_meta_types.hpp"
#include "utility/meta_utils/meta_utils.hpp"
#include "utility/movement/movement.hpp"

#include "networking/networked_periodic_signal_quantizer/networked_periodic_signal_quantizer.hpp"
#include "networking/packet_handler/packet_handler.hpp"
#include "networking/server_networking/network.hpp"
#include "networking/packets/packets.hpp"

#include "graphics/fps_camera/fps_camera.hpp"

#include "system_logic/update_physics_character/update_physics_character.hpp"
#include "system_logic/create_world/create_world.hpp"
#include "system_logic/interpolate/interpolate.hpp"
#include "system_logic/physics/physics.hpp"

#include <Jolt/Jolt.h>
#include <Jolt/Physics/Character/CharacterVirtual.h>

#include "meta_program/meta_program.hpp"

CharacterPhysicsState get_state(JPH::Ref<JPH::CharacterVirtual> &physics_character) {
    auto pos = physics_character->GetPosition();
    auto vel = physics_character->GetLinearVelocity();
    return {pos, vel};
};

// This should be replaced with the server character.
struct NonLocalClientCharacterBase {
    NonLocalClientCharacterBase(JPH::Ref<JPH::CharacterVirtual> physics_character)
        : physics_character(physics_character) {};

    // NOTE: having physics characters on the client isn't a bad thing, when we run client side physics updates, it
    // actually makes things more precise I believe... (what about the fact that other players are "in the past"?)
    JPH::Ref<JPH::CharacterVirtual> physics_character;

    void set_position(const glm::vec3 &position) { physics_character->SetPosition(g2j(position)); }
};

using ClientIdToPhysicsState = std::unordered_map<unsigned int, JPH::StateRecorderImpl>;

struct Game {

    // startfold systems
    FixedFrequencyLoop main_loop{1024};
    Network network;
    PacketHandler packet_handler;
    Physics physics;
    // endfold

    std::unordered_map<unsigned int, CharacterPhysicsState> game_state_id_to_target_physics_state;
    unsigned int game_state_id = 0;
    TemporalBinarySwitch fire_tbs;
    std::vector<SoundType> sounds_this_tick;
    movement::RotatingMovement rotating_movement{8, glm_utils::y * -8.f, glm_utils::y, 0.25};

    unsigned int w = 0, h = 0; // dummy
    FPSCamera fps_camera{w, h};
    JPH::Ref<JPH::CharacterVirtual> physics_character;
    JPH::Ref<JPH::CharacterVirtual> physics_target = physics.create_character(1);

    std::unordered_map<unsigned int, NonLocalClientCharacterBase> client_id_to_non_local_client_character_base;

    PeriodicSignal process_client_updates_signal{60};
    std::vector<ClientUpdateData> new_client_update_data;
    bool client_has_connected = false;

    NetworkedPeriodicSignalQuantizer<CharacterUpdateDataTimeBundle> bundle_quantizer;

    Game() {
        auto world = create_world();
        auto raw_world = collection_utils::map_vector(
            world, [](draw_info::IVPColor ivpc) { return draw_info::IndexedVertexPositions{ivpc}; });

        physics.load_model_into_physics_world(raw_world);

        packet_handler.register_handler(PacketType::CLIENT_UPDATE_DATA, [&](std::vector<uint8_t> buffer) {
            auto client_update_data_packet = meta_program->deserialize_ClientUpdateDataPacket(buffer);
            global_logger->info("just received {}",
                                meta_program->ClientUpdateDataPacket_to_string(client_update_data_packet));

            if (client_update_data_processing_method ==
                ClientUpdateDataProcessingMethod::UPDATE_STATE_AT_FIXED_FREQUENCY_USING_NPSQ) {
                // NOTE: we know at(0) is valid because of how we're sending over now.
                bundle_quantizer.push(
                    client_update_data_packet.client_update_data.character_update_data_time_bundles.at(0));
            } else {
                new_client_update_data.push_back(client_update_data_packet.client_update_data);
            }
        });

        bundle_quantizer.output_emitter.connect<std::optional<CharacterUpdateDataTimeBundle>>(
            [&](const std::optional<CharacterUpdateDataTimeBundle> &cud_bundle) {
                GlobalLogSection _("bundle quantizer new state received");

                std::optional<CharacterUpdateDataTimeBundle> best_bundle_to_use = std::nullopt;

                if (cud_bundle) {
                    best_bundle_to_use = cud_bundle;
                } else {
                    if (last_processed_cud_bundle) {
                        best_bundle_to_use = last_processed_cud_bundle;
                    }
                }

                if (best_bundle_to_use == std::nullopt) {
                    global_logger->warn("there was no best bundle to use, this should only happen at the start when at "
                                        "least one bundle has not yet been processed.");
                    // NOTE: we need to think if just early returning is fine here, imo it is because we're just waiting
                    // for npsq to return us a real cud bundle.
                    return;
                }

                process_cud_bundle(*best_bundle_to_use);
                last_processed_cud_bundle = best_bundle_to_use;

                send_out_game_state_packet();
            });

        client_id_to_non_local_client_character_base.emplace(1, physics_target);

        physics_target->SetPosition(JPH::Vec3(5, 5, 5));

        std::function<void(unsigned int)> on_connect = [&](unsigned int client_id) {
            global_logger->info("client_connected");
            client_has_connected = true;
            physics_character = physics.create_character(0);
        };

        network.set_on_connect_callback(on_connect);
    }

    void start() {
        auto tick_fun = [&](double dt) { tick(dt); };
        auto term = [&]() { return false; };
        main_loop.logging_enabled = true;
        main_loop.start(tick_fun, term);
    }

    enum class ClientUpdateDataProcessingMethod {
        // this methodology is wrong because it means that if you're packet doesn't get there you just freeze in place.
        ONLY_UPDATE_STATE_WHILE_PROCESSING_CLIENT_UPDATED_DATA,
        // this is proper but will introduce reconciliation deltas when there are ticks with non cud's that were
        // processed.
        UPDATE_STATE_AT_FIXED_FREQUENCY,
        UPDATE_STATE_AT_FIXED_FREQUENCY_USING_NPSQ,
    };

    ClientUpdateDataProcessingMethod client_update_data_processing_method =
        ClientUpdateDataProcessingMethod::ONLY_UPDATE_STATE_WHILE_PROCESSING_CLIENT_UPDATED_DATA;

    std::optional<ClientUpdateData> last_processed_cud;
    std::optional<CharacterUpdateDataTimeBundle> last_processed_cud_bundle;

    // optional because initially no value
    std::optional<unsigned int> last_applied_cpud_id;
    std::optional<unsigned int> last_applied_ccud_id;
    std::optional<unsigned int> last_applied_cud_id;

    std::optional<CharacterUpdateDataTimeBundle> get_best_client_bundle_to_update() {
        GlobalLogSection _("get_best_client_bundle_to_update");

        /**
         * NOTE: something important is happening here, the prorcess client updates signal is updating at 60 hz
         * which equating to 1/60 seconds per tick. We assume that exactly that much time has occurred (which is
         * false) but fine to do in practice (from my own observations thus far).
         *
         * Client bundles also have the property that when you sum up all the dts the add up to exactly 1/60
         * seconds, thus by actually using the dt's stored internal to the bundle we can recreate the state
         * exactly on the server by processing all all cpuds
         *
         */

        if (new_client_update_data.empty()) {
            global_logger->warn("there were no new client update datas since last iteration, this in-turn "
                                "means that there are no bundles to process, therefore we have an 'empty' "
                                "tick now, we will re-use the last processed one, this will produce "
                                "prediction deltas on the client.");
            return last_processed_cud_bundle;
        } else {
            global_logger->debug("there were new cuds since last time");
            if (new_client_update_data.size() >= 2) {
                global_logger->warn(
                    "we received more than one client update datas since the last iteration this means we have "
                    "a 'double tick', but instead we'll just use the most recently received one, this will produce "
                    "prediction deltas on the client.");
            }
            auto most_recently_received_cud = new_client_update_data.back();
            if (most_recently_received_cud.character_update_data_time_bundles.empty()) {
                global_logger->warn("the most recently received cud had no time bundles, we will now "
                                    "re-use the last processed "
                                    "cud bundle, this will produce prediction deltas on the client.");
                return last_processed_cud_bundle;
            } else {
                if (most_recently_received_cud.character_update_data_time_bundles.size() >= 2) {
                    global_logger->warn(
                        "the most recently received cud had has more than one time bundle in it, we're just "
                        "going to use the most recent one, so we're skipping at least one client processed cud "
                        "bundle, this will produce prediction deltas on the client. ");
                }
                auto most_recently_received_cud_bundle =
                    most_recently_received_cud.character_update_data_time_bundles.back();

                return most_recently_received_cud_bundle;
            }
        }

        // // NOTE: as seen in the below warnings this is the cause of deltas on the client,
        // if (new_client_update_data.empty()) {
        //     if (last_processed_cud) {
        //         // if there are no new updates, we assume that the same update was received
        //         process_client_update_data(*last_processed_cud);
        //     } else {
        //         global_logger->info("there was no new client update data nor was there a last processed cud, "
        //                             "this is probably because we haven't received anything yet.");
        //     }
        // } else {
        //     if (new_client_update_data.size() >= 2) {
        //         global_logger->warn(
        //             "we received more than one client update datas since the last iteration this means we have "
        //             "a 'double tick', this will produce prediction deltas on the client.");
        //     }
        //     auto most_recently_received_cud = new_client_update_data.back();
        //
        //     if (most_recently_received_cud.character_update_data_time_bundles.empty()) {
        //
        //         if (last_processed_cud_bundle) {
        //             global_logger->warn("the most recently received cud had no time bundles, we will now "
        //                                 "re-use the last processed "
        //                                 "cud bundle, this will produce prediction deltas on the client.");
        //             process_cud_bundle(*last_processed_cud_bundle);
        //         }
        //     } else {
        //
        //         if (most_recently_received_cud.character_update_data_time_bundles.size() >= 2) {
        //             global_logger->warn(
        //                 "the most recently received cud had has more than one time bundle in it, we're just "
        //                 "going to use the most recent one, so we're skipping at least one client processed cud "
        //                 "bundle, this will produce prediction deltas on the client. ");
        //             auto most_recently_received_cud_bundle =
        //                 most_recently_received_cud.character_update_data_time_bundles.back();
        //         }
        //     }
        //
        //     process_client_update_data(most_recently_received_cud);
        //     last_processed_cud = most_recently_received_cud;
        // }
    }

    void tick(double dt) {
        GlobalLogSection _("tick");
        auto packets = network.get_network_events_since_last_tick();
        packet_handler.handle_packets(packets);

        bundle_quantizer.update();

        if (process_client_updates_signal.process_and_get_signal()) {
            GlobalLogSection _("process_client_updates_signal activated");

            if (client_update_data_processing_method ==
                ClientUpdateDataProcessingMethod::UPDATE_STATE_AT_FIXED_FREQUENCY_USING_NPSQ)
                return;

            switch (client_update_data_processing_method) {
            case ClientUpdateDataProcessingMethod::ONLY_UPDATE_STATE_WHILE_PROCESSING_CLIENT_UPDATED_DATA:
                /**
                 * this method makes it so that there are never any deltas during reconciliation (assuming perfect
                 * network) at the cost of game entities seemingly freezing up in space until packets get there to
                 * unfreeze it.
                 *
                 * In my opinion this is actually really bad because gravity doesn't just stop applying all of a sudden,
                 * other case is the better one
                 *
                 */
                for (auto &client_update_data : new_client_update_data) {
                    process_client_update_data(client_update_data);
                    last_processed_cud = client_update_data;
                }
                break;
            case ClientUpdateDataProcessingMethod::UPDATE_STATE_AT_FIXED_FREQUENCY: {
                GlobalLogSection _("UPDATE_STATE_AT_FIXED_FREQUENCY");

                auto cud_time_bundle_to_use = get_best_client_bundle_to_update();
                if (cud_time_bundle_to_use) {
                    process_cud_bundle(*cud_time_bundle_to_use);
                    last_processed_cud_bundle = cud_time_bundle_to_use;
                }

                break;
            }
            }

            new_client_update_data.clear();

            // we may as well send out right after...
            send_out_game_state_packet();
        }
    }

    void send_out_game_state_packet() {
        bool processed_at_least_one_cud = last_applied_cud_id.has_value();
        if (client_has_connected and processed_at_least_one_cud) {
            GameStatePacket gsp = construct_game_state_packet();
            auto buffer = meta_program->serialize_GameStatePacket(gsp);
            network.unreliable_broadcast(buffer.data(), buffer.size());
            global_logger->info("just sent {}", meta_program->GameStatePacket_to_string(gsp));
            game_state_id++;
        }
    }

    /**
     * @pre last_applied_cud_id is not nullopt
     */
    GameStatePacket construct_game_state_packet() {

        auto new_physics_target_pos =
            // g2j(rotating_movement.get_current_position(process_client_updates_signal.get_last_delta_time()));
            physics_character->GetPosition();
        physics_target->SetPosition(new_physics_target_pos + JPH::Vec3(2, 2, 2));
        CharacterPhysicsState target_physics_state = get_state(physics_target);

        game_state_id_to_target_physics_state.emplace(game_state_id, target_physics_state);

        // TODO: don't need to two separate thigns?
        IdTaggedCharacterPhysicsState id_tagged_character_physics_state{*last_applied_cud_id,
                                                                        get_state(physics_character)};

        IdTaggedCharacterCameraState id_tagged_character_camera_state{*last_applied_cud_id,
                                                                      get_camera_state(fps_camera)};

        GameState gs{game_state_id, id_tagged_character_physics_state, id_tagged_character_camera_state,
                     target_physics_state, sounds_this_tick};

        sounds_this_tick.clear();

        GameStatePacket gsp;
        gsp.packet_header.type = PacketType::GAME_STATE;
        gsp.packet_header.size_of_data_without_header = meta_program->size_when_serialized_GameState(gs);
        gsp.game_state = gs;
        return gsp;
    }

    void process_client_update_data(ClientUpdateData &client_update_data) {
        // TODO: one of the causes of stutter comes from the fact that when there is an empty time bundle this loop does
        // not iterate and thus nothing moves, I thought I had fixed this in the outer if statement but that's only
        // check if there are any cuds which intern contain a vector of bundles... We pretty need the same logic here,
        // and perhaps it only needs to occur on the bundles and not the updates themselves? also there is shooting
        // logic in here and so we need to consider that too
        for (const auto &new_character_update_data_time_bundle :
             client_update_data.character_update_data_time_bundles) {
            process_cud_bundle(new_character_update_data_time_bundle);
        }
    }

    void process_cud_bundle(const CharacterUpdateDataTimeBundle &new_character_update_data_time_bundle) {
        GlobalLogSection _("process_cud_bundle");

        for (auto &id_tagged_character_update_data :
             new_character_update_data_time_bundle.id_tagged_character_update_datas) {
            // NOTE: when no packets are received, the character is not simulated, needs to be fixed up
            // in the future.

            bool legacy_logging = false;
            { // physics
                LogSection _(*global_logger, "apply_update");
                if (legacy_logging) {
                    IdTaggedCharacterPhysicsUpdateData id_tagged_character_physics_update_data{
                        id_tagged_character_update_data.id,
                        id_tagged_character_update_data.character_update_data.character_physics_update_data};
                    global_logger->info("applying update: {}",
                                        meta_program->IdTaggedCharacterPhysicsUpdateData_to_string(
                                            id_tagged_character_physics_update_data));
                } else {
                    global_logger->info(
                        "applying update: [id={}] {}", id_tagged_character_update_data.id,
                        meta_program->CharacterPhysicsUpdateData_to_string(
                            id_tagged_character_update_data.character_update_data.character_physics_update_data));
                }

                // this logging language should be shared for easier log anaylsis.
                global_logger->info("state before applying: {}",
                                    meta_program->CharacterPhysicsState_to_string(get_state(physics_character)));
                update_physics_character(
                    id_tagged_character_update_data.character_update_data.character_physics_update_data,
                    physics_character, physics);
                global_logger->info("state after applying: {}",
                                    meta_program->CharacterPhysicsState_to_string(get_state(physics_character)));
            }
            { // camera
                LogSection _(*global_logger, "apply_update");

                if (legacy_logging) {
                    IdTaggedCharacterCameraUpdateData id_tagged_character_camera_update_data{
                        id_tagged_character_update_data.id,
                        id_tagged_character_update_data.character_update_data.character_camera_update_data};
                    global_logger->info("applying input: {}", meta_program->IdTaggedCharacterCameraUpdateData_to_string(
                                                                  id_tagged_character_camera_update_data));
                } else {
                    global_logger->info(
                        "applying input: {}",
                        meta_program->CharacterCameraUpdateData_to_string(
                            id_tagged_character_update_data.character_update_data.character_camera_update_data));
                }

                global_logger->info("state before updating: {}",
                                    meta_program->CharacterCameraState_to_string(get_camera_state(fps_camera)));
                fps_camera.mouse_callback(
                    id_tagged_character_update_data.character_update_data.character_camera_update_data.mouse_position_x,
                    id_tagged_character_update_data.character_update_data.character_camera_update_data.mouse_position_y,
                    id_tagged_character_update_data.character_update_data.character_camera_update_data.sensitivity);
                global_logger->info("state after updating: {}",
                                    meta_program->CharacterCameraState_to_string(get_camera_state(fps_camera)));

                //     last_applied_ccud_id = id_tagged_character_camera_update_data.id;
            }
            {
                fire_tbs.set(
                    id_tagged_character_update_data.character_update_data.character_firing_update_data.fire_pressed);

                if (fire_tbs.just_switched_on()) { // This can only be true when fire tbs is true
                                                   // meaning that the opt value is

                    // startfold restore target state
                    DataToReconstructNonLocalCharacterPhysicsStateWithEntityInterpolationWhenFiringOnServer
                        data_to_reconstruct_non_local_character_physics_state_with_entity_interpolation_when_firing_on_server =
                            id_tagged_character_update_data.character_update_data.character_firing_update_data
                                .data_to_reconstruct_non_local_character_physics_state_with_entity_interpolation_when_firing_on_server
                                .value(); // this is ok because of the fact that fire was pressed

                    auto target_start = game_state_id_to_target_physics_state.at(
                        data_to_reconstruct_non_local_character_physics_state_with_entity_interpolation_when_firing_on_server
                            .id_of_interpolation_start_game_state_id_for_non_local_character_state);

                    auto target_end = game_state_id_to_target_physics_state.at(
                        data_to_reconstruct_non_local_character_physics_state_with_entity_interpolation_when_firing_on_server
                            .id_of_interpolation_end_game_state_id_for_non_local_character_state);

                    auto target_physics_state_when_client_fired = interpolate(
                        target_start, target_end,
                        data_to_reconstruct_non_local_character_physics_state_with_entity_interpolation_when_firing_on_server
                            .interpolation_percent_when_fired);

                    auto before_position = physics_target->GetPosition();
                    physics_target->SetPosition(target_physics_state_when_client_fired.position);

                    // endfold

                    auto hitscan_ray = g2j(fps_camera.transform.compute_forward_vector() * 1000.0);
                    auto hitscan_ray_origin = physics_character->GetPosition() + physics.eyes_offset_from_center;
                    JPH::RayCast aim_ray(hitscan_ray_origin, hitscan_ray);

                    std::unordered_map<unsigned int, Physics::CharacterHitscanContext>
                        client_id_to_character_hitscan_context;
                    for (auto &[client_id, non_local_client_character_base] :
                         client_id_to_non_local_client_character_base) {
                        client_id_to_character_hitscan_context.emplace(
                            client_id,
                            Physics::CharacterHitscanContext{non_local_client_character_base.physics_character});
                    }

                    // NOTE: we're using 0 here becauset here's only ever one player as of right now.
                    unsigned int firing_client_id = 0;
                    Physics::HitscanResult hr = physics.fire_hitscan_weapon(
                        aim_ray, client_id_to_character_hitscan_context, firing_client_id, physics.created_body_ids);

                    global_logger->info("just fired with yaw={}, pitch={}, position={}",
                                        fps_camera.transform.get_rotation_yaw(),
                                        fps_camera.transform.get_rotation_pitch(),
                                        meta_program->JPH_Vec3_to_string(hitscan_ray_origin));

                    if (hr.hit_character()) {
                        unsigned int id = *hr.hit_character_id;
                        auto pos = client_id_to_non_local_client_character_base.at(id).physics_character->GetPosition();
                        global_logger->info("hit player with id {} they had position {}", id,
                                            meta_program->JPH_Vec3_to_string(pos));
                        sounds_this_tick.push_back(SoundType::SERVER_HIT);
                    } else if (hr.hit_world_object()) {
                        global_logger->info("hit world object body {} at fraction {}", hr.hit_world_body_id->GetIndex(),
                                            *hr.hit_fraction);
                        sounds_this_tick.push_back(SoundType::SERVER_MISS);
                    } else {
                        // nothing was hit
                        global_logger->info("hit nothing");
                        sounds_this_tick.push_back(SoundType::SERVER_MISS);
                    }

                    // restore state
                    physics_target->SetPosition(before_position);
                }
            }
            last_applied_cud_id = id_tagged_character_update_data.id;
            // last_applied_cpud_id = itcpud.id;
        }
    }
};

int main() {

    global_logger->remove_all_sinks();
    global_logger->add_file_sink("logs/logs.txt");

    Configuration configuration{"assets/config/user_cfg.ini"};

    if (configuration.get_value("general", "development_mode") == "on") {
        register_glm_meta_types();
        register_jolt_meta_types();
        meta_utils::CustomTypeExtractionSettings settings("src/networking/packet_types/packet_types.hpp");
        meta_utils::CustomTypeExtractionSettings settings1("src/networking/packet_data/packet_data.hpp");
        meta_utils::CustomTypeExtractionSettings settings2("src/sound/sound_types/sound_types.hpp");
        meta_utils::CustomTypeExtractionSettings settings3(
            "src/system_logic/data_to_reconstruct_client_game_state_when_firing_on_server/"
            "data_to_reconstruct_client_game_state_when_firing_on_server.hpp");
        meta_utils::CustomTypeExtractionSettings settings4(
            "src/system_logic/reconciliation_types/reconciliation_types.hpp");
        meta_utils::CustomTypeExtractionSettings settings5("src/networking/packets/packets.hpp");
        meta_utils::register_custom_types_into_meta_types(
            {settings, settings1, settings2, settings3, settings4, settings5});
        meta_utils::generate_string_invokers_program_wide({}, meta_utils::meta_types.get_concrete_types());
    }

    Game game;
    game.client_update_data_processing_method =
        Game::ClientUpdateDataProcessingMethod::UPDATE_STATE_AT_FIXED_FREQUENCY_USING_NPSQ;
    game.start();
}
