#include "update_physics_character.hpp"

void update_physics_character(const CharacterPhysicsUpdateData &cpud,
                              JPH::Ref<JPH::CharacterVirtual> &physics_character, Physics &physics) {
    // NOTE: when reconciling physics_character's state is authoratively set to the newly received server state
    auto current_velocity = physics_character->GetLinearVelocity();

    bool is_on_ground = physics_character->GetGroundState() == JPH::CharacterVirtual::EGroundState::OnGround;
    movement::GroundState ground_state = is_on_ground ? movement::GroundState::OnGround : movement::GroundState::InAir;

    auto new_velocity_glm = movement::get_new_fps_character_velocity(
        j2g(current_velocity), cpud.client_input_state, cpud.xy_forward_vector_camera, cpud.dt, ground_state);

    physics_character->SetLinearVelocity(g2j(new_velocity_glm));
    auto set_vel = physics_character->GetLinearVelocity();
    physics.update_specific_character_by_id(cpud.dt, 0);
    set_vel = physics_character->GetLinearVelocity();
    physics.refresh_contacts(physics_character);
}
