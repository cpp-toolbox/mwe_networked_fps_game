#include "sound/sound_types/sound_types.hpp"
#include "utility/temporal_binary_switch/temporal_binary_switch.hpp"
#include "utility/fixed_frequency_loop/fixed_frequency_loop.hpp"
#include "utility/config_file_parser/config_file_parser.hpp"
#include "utility/jolt_meta_types/jolt_meta_types.hpp"
#include "utility/periodic_signal/periodic_signal.hpp"
#include "utility/glm_meta_types/glm_meta_types.hpp"
#include "utility/meta_utils/meta_utils.hpp"
#include "utility/movement/movement.hpp"

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

int main() {

    global_logger.remove_all_sinks();
    global_logger.add_file_sink("logs/logs.txt");

    Configuration configuration{"assets/config/user_cfg.ini"};

    meta_program::MetaProgram mp({meta_utils::meta_types.get_concrete_types()});
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

    FixedFrequencyLoop main_loop(1024);
    Network network;
    PacketHandler packet_handler;
    Physics physics;

    auto world = create_world();
    auto raw_world = collection_utils::map_vector(
        world, [](draw_info::IVPColor ivpc) { return draw_info::IndexedVertexPositions{ivpc}; });

    physics.load_model_into_physics_world(raw_world);

    std::vector<ClientUpdateData> new_client_update_data;
    packet_handler.register_handler(PacketType::CLIENT_UPDATE_DATA, [&](std::vector<uint8_t> buffer) {
        auto client_update_data_packet = mp.deserialize_ClientUpdateDataPacket(buffer);
        global_logger.info("just received {}", mp.ClientUpdateDataPacket_to_string(client_update_data_packet));
        new_client_update_data.push_back(client_update_data_packet.client_update_data);
    });

    unsigned int w = 0, h = 0; // dummy
    FPSCamera fps_camera{w, h};
    JPH::Ref<JPH::CharacterVirtual> physics_character;
    JPH::Ref<JPH::CharacterVirtual> physics_target = physics.create_character(1);

    std::unordered_map<unsigned int, NonLocalClientCharacterBase> client_id_to_non_local_client_character_base;
    client_id_to_non_local_client_character_base.emplace(1, physics_target);

    physics_target->SetPosition(JPH::Vec3(5, 5, 5));

    bool client_has_connected = false;
    std::function<void(unsigned int)> on_connect = [&](unsigned int client_id) {
        global_logger.info("client_connected");
        client_has_connected = true;
        physics_character = physics.create_character(0);
    };

    network.set_on_connect_callback(on_connect);
    PeriodicSignal process_client_updates_signal{60};

    std::unordered_map<unsigned int, CharacterPhysicsState> game_state_id_to_target_physics_state;
    unsigned int game_state_id = 0;
    // optional because initially no value
    std::optional<unsigned int> last_applied_cpud_id;
    std::optional<unsigned int> last_applied_ccud_id;
    std::optional<unsigned int> last_applied_cud_id;
    TemporalBinarySwitch fire_tbs;
    std::vector<SoundType> sounds_this_tick;
    movement::RotatingMovement rotating_movement{8, glm_utils::y * -8.f, glm_utils::y, 0.25};
    auto tick = [&](double dt) {
        auto packets = network.get_network_events_since_last_tick();
        packet_handler.handle_packets(packets);

        if (process_client_updates_signal.process_and_get_signal()) {

            for (auto client_update_data : new_client_update_data) {
                // startfold update physics state
                for (auto new_character_update_data_time_bundle :
                     client_update_data.character_update_data_time_bundles) {
                    for (auto &id_tagged_character_update_data :
                         new_character_update_data_time_bundle.id_tagged_character_update_datas) {
                        // NOTE: when no packets are received, the character is not simulated, needs to be fixed up in
                        // the future.

                        bool legacy_logging = true;
                        {
                            LogSection _(global_logger, "apply_update");
                            if (legacy_logging) {
                                IdTaggedCharacterPhysicsUpdateData id_tagged_character_physics_update_data{
                                    id_tagged_character_update_data.id,
                                    id_tagged_character_update_data.character_update_data
                                        .character_physics_update_data};
                                global_logger.info("Applying input: {}",
                                                   mp.IdTaggedCharacterPhysicsUpdateData_to_string(
                                                       id_tagged_character_physics_update_data));
                            } else {
                                global_logger.info("Applying input: {}",
                                                   mp.CharacterPhysicsUpdateData_to_string(
                                                       id_tagged_character_update_data.character_update_data
                                                           .character_physics_update_data));
                            }

                            global_logger.info("State before updating: {}",
                                               mp.CharacterPhysicsState_to_string(get_state(physics_character)));
                            update_physics_character(
                                id_tagged_character_update_data.character_update_data.character_physics_update_data,
                                physics_character, physics);
                            global_logger.info("State after updating: {}",
                                               mp.CharacterPhysicsState_to_string(get_state(physics_character)));
                        }
                        {
                            LogSection _(global_logger, "apply_update");

                            if (legacy_logging) {
                                IdTaggedCharacterCameraUpdateData id_tagged_character_camera_update_data{
                                    id_tagged_character_update_data.id,
                                    id_tagged_character_update_data.character_update_data.character_camera_update_data};
                                global_logger.info("Applying input: {}", mp.IdTaggedCharacterCameraUpdateData_to_string(
                                                                             id_tagged_character_camera_update_data));
                            } else {
                                global_logger.info("Applying input: {}",
                                                   mp.CharacterCameraUpdateData_to_string(
                                                       id_tagged_character_update_data.character_update_data
                                                           .character_camera_update_data));
                            }

                            global_logger.info("State before updating: {}",
                                               mp.CharacterCameraState_to_string(get_camera_state(fps_camera)));
                            fps_camera.mouse_callback(id_tagged_character_update_data.character_update_data
                                                          .character_camera_update_data.mouse_position_x,
                                                      id_tagged_character_update_data.character_update_data
                                                          .character_camera_update_data.mouse_position_y,
                                                      id_tagged_character_update_data.character_update_data
                                                          .character_camera_update_data.sensitivity);
                            global_logger.info("State after updating: {}",
                                               mp.CharacterCameraState_to_string(get_camera_state(fps_camera)));

                            //     last_applied_ccud_id = id_tagged_character_camera_update_data.id;
                        }
                        {
                            fire_tbs.set(id_tagged_character_update_data.character_update_data
                                             .character_firing_update_data.fire_pressed);

                            if (fire_tbs.just_switched_on()) { // This can only be true when fire tbs is true meaning
                                                               // that the opt value is

                                // startfold restore target state
                                DataToReconstructNonLocalCharacterPhysicsStateWithEntityInterpolationWhenFiringOnServer
                                    data_to_reconstruct_non_local_character_physics_state_with_entity_interpolation_when_firing_on_server =
                                        id_tagged_character_update_data.character_update_data
                                            .character_firing_update_data
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
                                auto hitscan_ray_origin =
                                    physics_character->GetPosition() + physics.eyes_offset_from_center;
                                JPH::RayCast aim_ray(hitscan_ray_origin, hitscan_ray);

                                std::unordered_map<unsigned int, Physics::CharacterHitscanContext>
                                    client_id_to_character_hitscan_context;
                                for (auto &[client_id, non_local_client_character_base] :
                                     client_id_to_non_local_client_character_base) {
                                    client_id_to_character_hitscan_context.emplace(
                                        client_id, Physics::CharacterHitscanContext{
                                                       non_local_client_character_base.physics_character});
                                }

                                // NOTE: we're using 0 here becauset here's only ever one player as of right now.
                                unsigned int firing_client_id = 0;
                                Physics::HitscanResult hr =
                                    physics.fire_hitscan_weapon(aim_ray, client_id_to_character_hitscan_context,
                                                                firing_client_id, physics.created_body_ids);

                                global_logger.info("just fired with yaw={}, pitch={}, position={}",
                                                   fps_camera.transform.get_rotation_yaw(),
                                                   fps_camera.transform.get_rotation_pitch(),
                                                   mp.JPH_Vec3_to_string(hitscan_ray_origin));

                                if (hr.hit_character()) {
                                    unsigned int id = *hr.hit_character_id;
                                    auto pos = client_id_to_non_local_client_character_base.at(id)
                                                   .physics_character->GetPosition();
                                    global_logger.info("hit player with id {} they had position {}", id,
                                                       mp.JPH_Vec3_to_string(pos));
                                    sounds_this_tick.push_back(SoundType::SERVER_HIT);
                                } else if (hr.hit_world_object()) {
                                    global_logger.info("hit world object body {} at fraction {}",
                                                       hr.hit_world_body_id->GetIndex(), *hr.hit_fraction);
                                    sounds_this_tick.push_back(SoundType::SERVER_MISS);
                                } else {
                                    // nothing was hit
                                    global_logger.info("hit nothing");
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
                // endfold
            }
            new_client_update_data.clear();

            auto new_physics_target_pos =
                g2j(rotating_movement.get_current_position(process_client_updates_signal.get_last_delta_time()));
            physics_target->SetPosition(new_physics_target_pos);
            CharacterPhysicsState target_physics_state = get_state(physics_target);

            game_state_id_to_target_physics_state.emplace(game_state_id, target_physics_state);

            // we may as well send out right after...

            if (client_has_connected and last_applied_cud_id.has_value()) {
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
                gsp.packet_header.size_of_data_without_header = mp.size_when_serialized_GameState(gs);
                gsp.game_state = gs;

                auto buffer = mp.serialize_GameStatePacket(gsp);
                network.unreliable_broadcast(buffer.data(), buffer.size());
                global_logger.info("just sent {}", mp.GameStatePacket_to_string(gsp));
                game_state_id++;
            }
        }
    };

    auto always_false = []() -> bool { return false; };

    main_loop.start(tick, always_false);
}
