/*
 * next step is to debug some of the shuddering caused by the networked interpolator as compared to raw non-entity
 * interpolation
 *
 * next up is to test it out on windows now with the new setup.
 *
 * TODO: we need to debug why network tick takes so long so we need so logging/timing utilties for this.
 */

#include <iostream>

#include "graphics/shader_standard/shader_standard.hpp"
#include "graphics/vertex_geometry/vertex_geometry.hpp"
#include "graphics/draw_info/draw_info.hpp"
#include "graphics/colors/colors.hpp"

#include "utility/logger/logger.hpp"
#include "utility/networked_periodic_signal_quantizer/networked_periodic_signal_quantizer.hpp"
#include "utility/jolt_glm_type_conversions/jolt_glm_type_conversions.hpp"
#include "utility/temporal_binary_switch/temporal_binary_switch.hpp"
#include "utility/networked_interpolator/networked_interpolator.hpp"
#include "utility/collection_utils/collection_utils.hpp"
#include "utility/periodic_signal/periodic_signal.hpp"
#include "utility/jolt_meta_types/jolt_meta_types.hpp"
#include "utility/glm_meta_types/glm_meta_types.hpp"
#include "utility/glm_printing/glm_printing.hpp"
#include "utility/meta_utils/meta_utils.hpp"

#include "networking/packet_handler/packet_handler.hpp"
#include "networking/client_networking/network.hpp"
#include "networking/packets/packets.hpp"

#include "system_logic/character_physics_update_data_time_bundler/character_physics_update_data_time_bundler.hpp"
#include "system_logic/update_physics_character/update_physics_character.hpp"
#include "system_logic/reconciliation_types/reconciliation_types.hpp"
#include "system_logic/toolbox_engine/toolbox_engine.hpp"
#include "system_logic/reconciliation/reconciliation.hpp"
#include "system_logic/create_world/create_world.hpp"
#include "system_logic/interpolate/interpolate.hpp"
#include "system_logic/physics/physics.hpp"

#include "meta_program/meta_program.hpp"

struct NonLocalClientCharacterBase {
    NonLocalClientCharacterBase(JPH::Ref<JPH::CharacterVirtual> physics_character)
        : physics_character(physics_character) {};

    // NOTE: having physics characters on the client isn't a bad thing, when we run client side physics updates, it
    // actually makes things more precise I believe... (what about the fact that other players are "in the past"?)
    JPH::Ref<JPH::CharacterVirtual> physics_character;

    void set_position(const glm::vec3 &position) { physics_character->SetPosition(g2j(position)); }
};

using PhysicsReconciliation = Reconciliation<CharacterPhysicsState, CharacterPhysicsUpdateData>;
using CameraReconciliation = Reconciliation<CharacterCameraState, CharacterCameraUpdateData>;
using ClientIdToNonLocalCharacterBase = std::unordered_map<unsigned int, NonLocalClientCharacterBase>;

int main() {

    global_logger->remove_all_sinks();
    global_logger->add_file_sink("logs/logs.txt");

    ToolboxEngine tbx_engine("client",
                             {ShaderType::ABSOLUTE_POSITION_WITH_COLORED_VERTEX,
                              ShaderType::CWL_V_TRANSFORMATION_UBOS_1024_WITH_COLORED_VERTEX},
                             {
                                 {SoundType::UI_HOVER, "assets/sounds/hover.wav"},
                                 {SoundType::UI_CLICK, "assets/sounds/click.wav"},
                                 {SoundType::UI_SUCCESS, "assets/sounds/success.wav"},
                                 {SoundType::SERVER_HIT, "assets/sounds/server_hit.wav"},
                                 {SoundType::SERVER_MISS, "assets/sounds/server_miss.wav"},
                                 {SoundType::CLIENT_HIT, "assets/sounds/client_hit.wav"},
                                 {SoundType::CLIENT_MISS, "assets/sounds/client_miss.wav"},
                             });

    std::function<void(double, double)> mouse_pos_callback = [&](double xpos, double ypos) {
        tbx_engine.input_state.glfw_cursor_pos_callback(xpos, ypos);
    };
    tbx_engine.glfw_lambda_callback_manager.set_cursor_pos_callback(mouse_pos_callback);
    tbx_engine.glfw_lambda_callback_manager.logging_enabled = true;

    if (tbx_engine.configuration.get_value("general", "development_mode") == "on") {
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

    // Thought: Should bundling even be done on the client side? what if we just sent out a ton of data and then the
    // server could determine when there's enough to tick? idk seems weird as well
    CharacterPhysicsUpdateDataTimeBundler character_physics_update_data_time_bundler;
    PeriodicSignal client_to_server_send_signal{60};

    Physics physics;
    std::vector<draw_info::IVPColor> objects_to_draw;
    auto floor = draw_info::IVPColor(vertex_geometry::generate_box(20, 1, 20), colors::aliceblue);
    floor.transform.set_translation_y(-10);
    draw_info::apply_transform(floor);
    objects_to_draw.push_back(floor);

    auto world = create_world();
    auto raw_world = collection_utils::map_vector(
        world, [](draw_info::IVPColor ivpc) { return draw_info::IndexedVertexPositions{ivpc}; });

    physics.load_model_into_physics_world(raw_world);

    std::string ip_address = tbx_engine.configuration.get_value("network", "server_ip").value_or("localhost");
    Network network(ip_address);
    PacketHandler packet_handler;

    // NOTE: this was done to reduce "multiple reconciliation" which occurred when mutliple game states were received on
    // the client, we had no other way of doing this because we were reconciling inside of the callback function which
    // makes the most sense (ie you should reconcile as soon as you get it), and thus we needed a way to only run it on
    // a particular packet. This reduces waste
    packet_handler.packet_type_to_handling_method.emplace(
        PacketType::GAME_STATE, PacketHandler::PacketTypeHandlingMethod::LAST_RECEIVED_PACKET_ONLY);

    NetworkedInterpolator<GameState> networked_interpolator{
        [](const GameState &start, const GameState &end, float t) { return interpolate(start, end, t); }, 60, true,
        [&](const GameState &gs) { return meta_program->GameState_to_string(gs); }};

    networked_interpolator.logging_enabled = true;
    networked_interpolator.networked_periodic_signal_quantizer.logging_enabled = true;

    networked_interpolator.start_state_changed_synchronization
        .connect<NetworkedInterpolator<GameState>::StartStateChangedSignal>(
            [&](const NetworkedInterpolator<GameState>::StartStateChangedSignal &sscs) {
                for (const auto &sound : sscs.state.sounds) {
                    tbx_engine.sound_system.queue_sound(sound);
                }
            });

    network.attempt_to_connect_to_server();

    // TODO: only do this once the connection is good ?
    JPH::Ref<JPH::CharacterVirtual> physics_character = physics.create_character(0);
    JPH::Ref<JPH::CharacterVirtual> physics_target = physics.create_character(1);

    // NOTE: this exists because I'm trying to simulate a situation where there would be multiple targets, but for now
    // there's probably only one, making this redundant a bit
    std::unordered_map<unsigned int, NonLocalClientCharacterBase> client_id_to_non_local_client_character_base;
    client_id_to_non_local_client_character_base.emplace(1, physics_target);

    draw_info::IVPColor crosshair{vertex_geometry::generate_annulus(0, 0, 0.02, 0.01, 8), colors::green};

    draw_info::IVPColor target_visual{
        vertex_geometry::generate_cylinder(8, physics.character_height_standing, physics.character_radius),
        colors::purple};

    // startfold physics reconciliation
    auto update = [&](CharacterPhysicsUpdateData &cpud, bool reconciling) {
        GlobalLogSection _("updating physics state");
        // NOTE: when reconciling physics_character's state is authoratively set to the newly received server state
        update_physics_character(cpud, physics_character, physics);
    };

    auto get_state = [&]() -> CharacterPhysicsState {
        auto pos = physics_character->GetPosition();
        auto vel = physics_character->GetLinearVelocity();
        return {pos, vel};
    };

    auto set_state = [&](const CharacterPhysicsState &cps) {
        physics_character->SetPosition(cps.position);
        physics_character->SetLinearVelocity(cps.velocity);

        // NOTE: the ground state of a player isn't updated usually after setting position, so if you were on the
        // ground, and the position takes you off the ground or vise versa we need to accoutn for that, note that it
        // might be better one day to use jolts entire physics state to restore all properties if needed.

        // NOTE: JORRIT: I think RefreshContacts should mostly fix this issue as it runs collision detection again
        // and updates the ground state, however it is not 100% the same thing as calling ExtendedUpdate as this can
        // also detect contacts that you touch during the update (but don't end up touching at the end of the step).
        physics.refresh_contacts(physics_character);
    };

    auto state_to_string = [&](const CharacterPhysicsState &s) {
        return meta_program->CharacterPhysicsState_to_string(s);
    };

    auto update_to_string = [&](const CharacterPhysicsUpdateData &u) {
        return meta_program->CharacterPhysicsUpdateData_to_string(u);
    };

    auto diff_to_string = [&](const CharacterPhysicsState &a, const CharacterPhysicsState &b) {
        std::ostringstream oss;
        auto position_diff = b.position - a.position;
        auto velocity_diff = b.velocity - a.velocity;
        oss << "delta position=" << meta_program->JPH_Vec3_to_string(position_diff) << ", "
            << "delta velocity=" << meta_program->JPH_Vec3_to_string(velocity_diff);
        return oss.str();
    };

    bool reconciliation_enabled =
        tbx_engine.configuration.get_value("network", "reconciliation").value_or("on") == "on";

    bool using_entity_interpolation =
        tbx_engine.configuration.get_value("network", "entity_interpolation").value_or("on") == "on";

    // endfold

    PhysicsReconciliation physics_character_reconciliation{update,          get_state,        set_state,
                                                           state_to_string, update_to_string, diff_to_string};

    // startfold camera reconciliation setup
    auto camera_update = [&](const CharacterCameraUpdateData &ccud, bool reconciling) {
        tbx_engine.fps_camera.mouse_callback(ccud.mouse_position_x, ccud.mouse_position_y, ccud.sensitivity);
    };

    auto get_camera_state_ = [&]() -> CharacterCameraState {
        return get_camera_state(tbx_engine.fps_camera);
        // auto yaw = tbx_engine.fps_camera.transform.get_rotation_yaw();
        // auto pitch = tbx_engine.fps_camera.transform.get_rotation_pitch();
        // auto lmpx = tbx_engine.fps_camera.mouse.last_mouse_position_x;
        // auto lmpy = tbx_engine.fps_camera.mouse.last_mouse_position_y;
        //
        // return {yaw, pitch, lmpx, lmpy};
    };

    auto set_camera_state = [&](const CharacterCameraState &ccs) {
        tbx_engine.fps_camera.transform.set_rotation_yaw(ccs.yaw);
        tbx_engine.fps_camera.transform.set_rotation_pitch(ccs.pitch);

        tbx_engine.fps_camera.mouse.last_mouse_position_x = ccs.last_mouse_position_x;
        tbx_engine.fps_camera.mouse.last_mouse_position_y = ccs.last_mouse_position_y;
    };

    auto camera_state_to_string = [&](const CharacterCameraState &s) {
        return meta_program->CharacterCameraState_to_string(s);
    };

    auto camera_update_to_string = [&](const CharacterCameraUpdateData &u) {
        return meta_program->CharacterCameraUpdateData_to_string(u);
    };

    auto camera_diff_to_string = [&](const CharacterCameraState &a, const CharacterCameraState &b) {
        std::ostringstream oss;
        oss << "delta yaw=" << (b.yaw - a.yaw) << ", "
            << "delta pitch=" << (b.pitch - a.pitch) << ", "
            << "delta last_mouse_position_x=" << (b.last_mouse_position_x - a.last_mouse_position_x) << ", "
            << "delta last_mouse_position_y=" << (b.last_mouse_position_y - a.last_mouse_position_y);
        return oss.str();
    };

    CameraReconciliation camera_reconciliation{camera_update,          get_camera_state_,       set_camera_state,
                                               camera_state_to_string, camera_update_to_string, camera_diff_to_string};
    // endfold

    Stopwatch game_state_receive_stopwatch_raw;
    Stopwatch game_state_receive_stopwatch_quantized;

    // NetworkedPeriodicSignalQuantizer<GameState> networked_periodic_signal_quantizer;

    // networked_periodic_signal_quantizer.output_emitter.connect<GameState>([&](const GameState &gs) {
    //     // game_state_receive_stopwatch_quantized.press();
    //     networked_interpolator.register_new_state(gs);
    // });

    // TODO: remove this probabaly.
    packet_handler.register_handler(PacketType::GAME_STATE, [&](std::vector<uint8_t> buffer) {
        auto gsp = meta_program->deserialize_GameStatePacket(buffer);
        global_logger->info("just received {}", meta_program->GameStatePacket_to_string(gsp));
        game_state_receive_stopwatch_raw.press();
        networked_interpolator.register_new_state(gsp.game_state);
        // networked_periodic_signal_quantizer.push(gsp.game_state);

        global_logger->info("raw receive macro stats: {}",
                            game_state_receive_stopwatch_raw.get_macro_stats().to_string());
        global_logger->info("raw receive micro stats: {}",
                            game_state_receive_stopwatch_raw.get_micro_stats().to_string());

        // global_logger->info("quantized receive macro stats: {}",
        //                    game_state_receive_stopwatch_quantized.get_macro_stats().to_string());
        // global_logger->info("quantized receive micro stats: {}",
        //                    game_state_receive_stopwatch_quantized.get_micro_stats().to_string());
        //
        // global_logger->info("networked_periodic_signal_quantizer missed emit percentage: {}",
        //                    networked_periodic_signal_quantizer.get_missed_emit_percentage());
        //
        // global_logger->info("networked_periodic_signal_quantizer average_size: {}",
        //                    networked_periodic_signal_quantizer.get_average_received_server_states_size());

        GameState gs = gsp.game_state;
        PhysicsReconciliation::IdTaggedState prits{
            gs.id_tagged_character_physics_state.character_physics_state,
            gs.id_tagged_character_physics_state.id_of_last_update_data_used_to_produce_this_state};

        CameraReconciliation::IdTaggedState crits{
            gs.id_tagged_character_camera_state.character_camera_state,
            gs.id_tagged_character_camera_state.id_of_last_update_data_used_to_produce_this_state};

        if (reconciliation_enabled) {
            physics_character_reconciliation.reconcile(prits);
            camera_reconciliation.reconcile(crits);
        }

        if (using_entity_interpolation) {
            // networked_interpolator.register_new_state(gs);
        } else {
            physics_target->SetPosition(gs.target_physics_state.position);
            physics_target->SetLinearVelocity(gs.target_physics_state.velocity);
            target_visual.transform.set_translation(j2g(gs.target_physics_state.position));
            global_logger->debug("just set physics_target position to: {}",
                                 vec3_to_string(j2g(gs.target_physics_state.position)));
        }
    });

    unsigned int client_update_data_packet_id = 0;
    unsigned int character_update_data_id = 0;
    unsigned int local_client_id = 0;
    TemporalBinarySwitch fire_tbs;

    auto tick = [&](double dt) {
        GlobalLogSection _("tick");
        global_logger->info("iteration number: {}", tbx_engine.main_loop.iteration_count);

        {
            GlobalLogSection _("tick set uniforms");
            // startfold set uniforms
            tbx_engine.shader_cache.set_uniform(ShaderType::CWL_V_TRANSFORMATION_UBOS_1024_WITH_COLORED_VERTEX,
                                                ShaderUniformVariable::CAMERA_TO_CLIP,
                                                tbx_engine.fps_camera.get_projection_matrix());

            tbx_engine.shader_cache.set_uniform(ShaderType::CWL_V_TRANSFORMATION_UBOS_1024_WITH_COLORED_VERTEX,
                                                ShaderUniformVariable::WORLD_TO_CAMERA,
                                                tbx_engine.fps_camera.get_view_matrix());

            auto [arx, ary] = tbx_engine.window.get_aspect_ratio_in_simplest_terms();

            tbx_engine.shader_cache.set_uniform(ShaderType::ABSOLUTE_POSITION_WITH_COLORED_VERTEX,
                                                ShaderUniformVariable::ASPECT_RATIO, glm::vec2(arx, ary));

            // endfold
        }

        {

            GlobalLogSection _("tick state updating");
            // startfold state updating
            std::vector mouse_interactible_elements_active = {tbx_engine.igs_menu_active};
            bool ignore_inputs = tbx_engine.active_mouse_mode == ToolboxEngine::ActiveMouseMode::MenuInteraction;

            // networked_periodic_signal_quantizer.update();
            networked_interpolator.update();

            if (using_entity_interpolation) {
                auto interpolated_game_state = networked_interpolator.get_state();
                if (interpolated_game_state) {

                    physics_target->SetPosition(interpolated_game_state->target_physics_state.position);
                    global_logger->debug("just set physics_target position to: {}",
                                         vec3_to_string(j2g(interpolated_game_state->target_physics_state.position)));
                    target_visual.transform.set_translation(
                        j2g(interpolated_game_state->target_physics_state.position));
                }
            }

            // startfold camera
            CharacterCameraUpdateData ccud;
            if (not ignore_inputs) {
                // NOTE: when we switch to menu mode and come back to camera control we get a huge delta because the
                // mouse was not updated during that time, this is something we should fix in the future, but I don't
                // care about right now
                ccud = CharacterCameraUpdateData(tbx_engine.input_state.mouse_position_x,
                                                 tbx_engine.input_state.mouse_position_y,
                                                 tbx_engine.fps_camera.active_sensitivity);
            } else { // the menu is active, in this case we want to keep sending the same thing over and over
                // TODO
            }

            // id_tagged_character_physics_update_data_since_last_client_to_server_send.push_back(itccud);

            // endfold

            auto bundle_constrained_dt = character_physics_update_data_time_bundler.get_bundle_constrained_dt(dt);
            global_logger->debug("just got bundle constrained dt: {}", bundle_constrained_dt);
            // auto bundle_constrained_dt = dt;

            ClientInputState cis(tbx_engine.input_state.is_pressed(EKey::w), tbx_engine.input_state.is_pressed(EKey::s),
                                 tbx_engine.input_state.is_pressed(EKey::d), tbx_engine.input_state.is_pressed(EKey::a),
                                 tbx_engine.input_state.is_pressed(EKey::SPACE));

            CharacterPhysicsUpdateData cpud{bundle_constrained_dt, cis,
                                            tbx_engine.fps_camera.transform.compute_xz_forward_vector()};

            // NOTE: this keeps the mouse feeling "live"
            // TODO: can we just combine these two by baking in yaw pitch into the physics character soon? idk yet this
            // is probably fine for now
            auto ccud_id = camera_reconciliation.apply_update(ccud);
            auto cpud_id = physics_character_reconciliation.apply_update(cpud);

            if (cpud_id != ccud_id) {
                global_logger->critical("the reconciliation needs to remain synchronnous killing myself now");
                return;
            }
            character_update_data_id = ccud_id;

            // startfold create cfud
            fire_tbs.set(tbx_engine.input_state.is_pressed(EKey::LEFT_MOUSE_BUTTON));
            bool fire_pressed = fire_tbs.is_on();

            // NOTE: if you fire on the client and send that over in ClientUpdataDataPacket with id X
            // then the server will probably also fire when it process this updata data, though if the packet never gets
            // there then it wouldn't, assuming we held down fire for X, X+1, ..., X+n, then the fire will probably
            // occur when the first one of those packets reaches the server, therefore it's probably the best to send
            // over the fire context whenever they're holding down fire so that we can try and reconstruct the state on
            // the server when we fired. Note that the server is authorative about firing

            std::optional<DataToReconstructNonLocalCharacterPhysicsStateWithEntityInterpolationWhenFiringOnServer>
                data_to_reconstruct_non_local_character_physics_state_with_entity_interpolation_when_firing_on_server;

            if (fire_pressed) { // A
                auto opt_start = networked_interpolator.get_active_start_state();
                auto opt_end = networked_interpolator.get_active_end_state();
                auto t = networked_interpolator.get_active_t();

                if (opt_start.has_value() and opt_end.has_value()) {
                    data_to_reconstruct_non_local_character_physics_state_with_entity_interpolation_when_firing_on_server =
                        DataToReconstructNonLocalCharacterPhysicsStateWithEntityInterpolationWhenFiringOnServer{
                            // TODO: problem: the variable name is not good here, thei d is actually the game state id,
                            // fix
                            // later
                            opt_start.value().id, opt_end.value().id, t};
                }

                // data_to_reconstruct_client_game_state_when_firing_on_server
                //     .id_of_last_applied_character_camera_update_data_before_firing = ccud_id;
                // data_to_reconstruct_client_game_state_when_firing_on_server
                //     .id_of_last_applied_character_physics_update_data_before_firing = cpud_id;
                // TODO: interpolation data when we can
            }

            CharacterFiringUpdateData cfud{
                fire_pressed,
                data_to_reconstruct_non_local_character_physics_state_with_entity_interpolation_when_firing_on_server};
            // endfold

            CharacterUpdateData character_update_data{cpud, ccud, cfud};
            IdTaggedCharacterUpdateData id_tagged_character_update_data{character_update_data_id,
                                                                        character_update_data};

            character_physics_update_data_time_bundler.register_cud(id_tagged_character_update_data);

            tbx_engine.fps_camera.transform.set_translation(j2g(physics_character->GetPosition()));
            tbx_engine.update_active_mouse_mode(tbx_engine.igs_menu_active);

            // SubtickHitscan::PotentiallyFireContext pfctx{fire_pressed, };

            // I only want to construct this once we know a firing occurred on the client, but do we know when

            // DataToReconstructLocalSubtickPhysicsStateWhenFiringOnServer
            //     data_to_reconstruct_local_subtick_physics_state_when_firing_on_server;
            //
            // // Or do we just need the active bundle, I think it's this.
            // std::vector<PhysicsReconciliation::IdTaggedStateUpdateData>
            //     physics_update_datas_applied_since_last_authorative_state =
            //         physics_character_reconciliation.get_update_datas_applied_since_last_authorative_state();
            //
            // for (const auto &physics_update_data_applied_since_last_authorative_state :
            //      physics_update_datas_applied_since_last_authorative_state) {
            //     data_to_reconstruct_local_subtick_physics_state_when_firing_on_server
            //         .id_tagged_character_physics_update_datas_applied_since_last_reconciliation.emplace_back(
            //             physics_update_data_applied_since_last_authorative_state.id,
            //             physics_update_data_applied_since_last_authorative_state.update_data);
            // }
            //
            // // we definitely need this though.
            // std::vector<CameraReconciliation::IdTaggedStateUpdateData>
            //     camera_update_datas_applied_since_last_authorative_state =
            //         camera_reconciliation.get_update_datas_applied_since_last_authorative_state();
            //
            // DataToReconstructLocalSubtickCameraStateWhenFiringOnServer
            //     data_to_reconstruct_local_subtick_camera_state_when_firing_on_server;
            //
            // for (const auto &camera_update_data_applied_since_last_authorative_state :
            //      camera_update_datas_applied_since_last_authorative_state) {
            //     data_to_reconstruct_local_subtick_camera_state_when_firing_on_server
            //         .id_tagged_character_camera_update_datas_applied_since_last_reconciliation.emplace_back(
            //             camera_update_data_applied_since_last_authorative_state.id,
            //             camera_update_data_applied_since_last_authorative_state.update_data);
            // }

            // subtick_hitscan.potentially_fire(const PotentiallyFireContext &pfctx);

            // NOTE: we allow for "local firing" in the sense that we still need to be able to go back in time on the
            // server so that we can fire accurtely from the players pov, the clients are not authorative, but it's
            // important for the server to accurately reconstruct the game stae in which the fired without allowing
            // client to stretch the truth too much (eg you can't shoot at someone really long in the past, cause then
            // you could kill people before they every saw you)
            if (fire_tbs.just_switched_on()) { // B

                global_logger->info("fire tbs isj usts witched on");

                // TODO: run local hitscan logic to see if we hit anything, its no longer subtick whatever but now it's
                // like interpolated? No not even that? actually yeah maybe that... but we just get the state from the
                // networked interpolator and then we can use that to check if we hit it...

                auto local_fps_camera = tbx_engine.fps_camera;

                auto hitscan_ray = g2j(local_fps_camera.transform.compute_forward_vector() * 1000.0);
                auto hitscan_ray_origin = physics_character->GetPosition() + physics.eyes_offset_from_center;
                JPH::RayCast aim_ray(hitscan_ray_origin, hitscan_ray);

                std::unordered_map<unsigned int, Physics::CharacterHitscanContext>
                    client_id_to_character_hitscan_context;
                for (auto &[client_id, non_local_client_character_base] :
                     client_id_to_non_local_client_character_base) {
                    client_id_to_character_hitscan_context.emplace(
                        client_id, Physics::CharacterHitscanContext{non_local_client_character_base.physics_character});
                }

                Physics::HitscanResult hr = physics.fire_hitscan_weapon(aim_ray, client_id_to_character_hitscan_context,
                                                                        local_client_id, physics.created_body_ids);

                global_logger->info("just fired with yaw={}, pitch={}, position={}",
                                    local_fps_camera.transform.get_rotation_yaw(),
                                    local_fps_camera.transform.get_rotation_pitch(),
                                    meta_program->JPH_Vec3_to_string(hitscan_ray_origin));

                if (hr.hit_character()) {
                    unsigned int id = *hr.hit_character_id;
                    auto pos = client_id_to_non_local_client_character_base.at(id).physics_character->GetPosition();
                    global_logger->info("hit player with id {} they had position {}", id,
                                        meta_program->JPH_Vec3_to_string(pos));
                    tbx_engine.sound_system.queue_sound(SoundType::CLIENT_HIT);
                } else if (hr.hit_world_object()) {
                    global_logger->info("hit world object body {} at fraction {}", hr.hit_world_body_id->GetIndex(),
                                        *hr.hit_fraction);
                    tbx_engine.sound_system.queue_sound(SoundType::CLIENT_MISS);
                } else {
                    // nothing was hit
                    global_logger->info("hit nothing");
                    tbx_engine.sound_system.queue_sound(SoundType::CLIENT_MISS);
                }
            }

            // endfold
        }

        {
            GlobalLogSection _("tick client to server send");
            // startfold client to server send
            if (client_to_server_send_signal.process_and_get_signal()) {
                ClientUpdateData client_update_data;
                client_update_data.character_update_data_time_bundles =
                    character_physics_update_data_time_bundler.take_bundles_since_last_send();
                client_update_data.id = client_update_data_packet_id;

                ClientUpdateDataPacket client_update_data_packet;

                client_update_data_packet.client_update_data = client_update_data;
                client_update_data_packet.packet_header.type = PacketType::CLIENT_UPDATE_DATA;

                client_update_data_packet.packet_header.size_of_data_without_header =
                    meta_program->size_when_serialized_ClientUpdateData(client_update_data_packet.client_update_data);

                auto buffer = meta_program->serialize_ClientUpdateDataPacket(client_update_data_packet);

                network.send_packet(buffer.data(), buffer.size());
                client_update_data_packet_id++;
                global_logger->info("just sent: {}",
                                    text_utils::format_nested_braces_string_recursive_with_newlines(
                                        meta_program->ClientUpdateDataPacket_to_string(client_update_data_packet)));

                for (const auto &bundle :
                     client_update_data_packet.client_update_data.character_update_data_time_bundles) {
                    global_logger->info("its time usage is: {}", bundle.total_amount_of_time());
                }
            }
            // endfold
        }

        {
            GlobalLogSection _("tick queue draw object");
            // startfold queue draw object
            tbx_engine.process_and_queue_render_input_graphics_sound_menu();
            tbx_engine.draw_chosen_engine_stats();
            for (auto &obj : world) {
                tbx_engine.batcher.cwl_v_transformation_ubos_1024_with_colored_vertex_shader_batcher.queue_draw(obj);
            }
            tbx_engine.batcher.cwl_v_transformation_ubos_1024_with_colored_vertex_shader_batcher.queue_draw(
                target_visual);

            tbx_engine.batcher.absolute_position_with_colored_vertex_shader_batcher.queue_draw(crosshair);
            // endfold
        }

        {
            GlobalLogSection _("tick queue draw and sounds");
            // startfold draw and sounds

            tbx_engine.sound_system.play_all_sounds();

            tbx_engine.batcher.absolute_position_with_colored_vertex_shader_batcher.draw_everything();

            tbx_engine.batcher.cwl_v_transformation_ubos_1024_with_colored_vertex_shader_batcher.draw_everything();
            tbx_engine.batcher.cwl_v_transformation_ubos_1024_with_colored_vertex_shader_batcher.upload_ltw_matrices();

            // endfold
        }

        {
            GlobalLogSection _("tick tbs process all");
            // TODO: I want to do away with this thing I think.
            TemporalBinarySignal::process_all();
        }

        // This is at the bottom because of this:
        // https://toolbox.cuppajoeman.com/programming/inside_of_fixed_frequency_loops_function_placement_matters.html
        {
            GlobalLogSection _("tick network");
            // startfold network
            auto packets = network.get_network_events_received_since_last_tick();
            packet_handler.handle_packets(packets);
            // endfold
        }
    };
    std::function<bool()> term = [&]() -> bool { return tbx_engine.window.window_should_close(); };

    tbx_engine.main_loop.logging_enabled = true;
    tbx_engine.start(tick, term);

    return 0;
}
