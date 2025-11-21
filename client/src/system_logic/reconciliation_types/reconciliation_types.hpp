#ifndef RECONCILIATION_TYPES_HPP
#define RECONCILIATION_TYPES_HPP

#include "../../graphics/fps_camera/fps_camera.hpp"
#include "../../utility/transform/transform.hpp"
#include "../data_to_reconstruct_client_game_state_when_firing_on_server/data_to_reconstruct_client_game_state_when_firing_on_server.hpp"
#include <Jolt/Jolt.h>
#include <glm/glm.hpp>

struct ClientInputState {
  bool forward_pressed = false;
  bool back_pressed = false;
  bool right_pressed = false;
  bool left_pressed = false;
  bool jump_pressed = false;

  glm::vec2 get_input_vector() const {
    glm::vec2 move(0.0f);

    // Forward/back correspond to y-axis
    if (forward_pressed)
      move.y += 1.0f;
    if (back_pressed)
      move.y -= 1.0f;

    // Left/right correspond to x-axis
    if (right_pressed)
      move.x += 1.0f;
    if (left_pressed)
      move.x -= 1.0f;

    // normalize if non-zero
    float len2 = glm::length(move);
    if (len2 > 0.0f)
      move /= std::sqrt(len2);

    return move;
  }
};

struct CharacterPhysicsState {
  JPH::Vec3 position;
  JPH::Vec3 velocity;
};

struct IdTaggedCharacterPhysicsState {
  unsigned int id_of_last_update_data_used_to_produce_this_state;
  CharacterPhysicsState character_physics_state;
};

// NOTE: an interesting thought came up when deducing this, at first my velocity
// update took in a whole fps camera, but it only uses a small piece of its
// state, it computed the forward and right vector in fact, so instead ofholding
// an entire fps camera we just extracted what we needed and updated the
// velocity update signature
struct CharacterPhysicsUpdateData {
  double dt;
  ClientInputState client_input_state;
  glm::vec3 xy_forward_vector_camera;
  // Movement movement;
};

// deprecated?
struct IdTaggedCharacterPhysicsUpdateData {
  unsigned int id;
  CharacterPhysicsUpdateData character_physics_update_data;
};

struct CharacterCameraState {
  double yaw;
  double pitch;
  double last_mouse_position_x;
  double last_mouse_position_y;
};

struct IdTaggedCharacterCameraState {
  unsigned int id_of_last_update_data_used_to_produce_this_state;
  CharacterCameraState character_camera_state;
};

struct CharacterCameraUpdateData {
  double mouse_position_x = 0;
  double mouse_position_y = 0;
  double sensitivity = 1;
};

struct CharacterFiringUpdateData {
  bool fire_pressed; // When this is true the below thing has_value
  std::optional<
      DataToReconstructNonLocalCharacterPhysicsStateWithEntityInterpolationWhenFiringOnServer>
      data_to_reconstruct_non_local_character_physics_state_with_entity_interpolation_when_firing_on_server;
};

// deprecated?
struct IdTaggedCharacterCameraUpdateData {
  unsigned int id;
  CharacterCameraUpdateData character_camera_update_data;
};

// NOTE: there's a complex idea going on, when you fire your gun at an enemy
// then by the time the server realizes you've fired that person might have
// already moved out of the way of your shot and you miss, because of this issue
// we have to do rollback. So shouldn't that whole logic apply to your own
// character? The answer is no because the server right now has a delayed
// position of where you are, this is because your inputs are still travelling
// to the server, and so by the time the cud with the data which makes the
// server realize you're firing gets there you will be in the correct place
// which is a weird concept
struct CharacterUpdateData {
  CharacterPhysicsUpdateData character_physics_update_data;
  CharacterCameraUpdateData character_camera_update_data;
  CharacterFiringUpdateData character_firing_update_data;
};

struct IdTaggedCharacterUpdateData {
  unsigned int id;
  CharacterUpdateData character_update_data;
};

// NOTE: this is not really reconciliation, I'm just putting it here for ease of
// use
// We say that a bundle is "filled" when its total amount of time ie equal to
// the servers tick period
struct CharacterUpdateDataTimeBundle {

  std::vector<IdTaggedCharacterUpdateData> id_tagged_character_update_datas;

  double total_amount_of_time() const {
    double total_dt = 0.0;
    for (const auto &entry : id_tagged_character_update_datas) {
      total_dt += entry.character_update_data.character_physics_update_data.dt;
    }
    return total_dt;
  }
};

// NOTE: just adding some helpers here
inline CharacterCameraState get_camera_state(FPSCamera &fps_camera) {
  auto yaw = fps_camera.transform.get_rotation_yaw();
  auto pitch = fps_camera.transform.get_rotation_pitch();
  auto lmpx = fps_camera.mouse.last_mouse_position_x;
  auto lmpy = fps_camera.mouse.last_mouse_position_y;

  return {yaw, pitch, lmpx, lmpy};
};

#endif // RECONCILIATION_TYPES_HPP
