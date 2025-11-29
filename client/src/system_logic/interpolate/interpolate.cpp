#include "interpolate.hpp"

CharacterPhysicsState interpolate(CharacterPhysicsState start, CharacterPhysicsState end, float t) {
    CharacterPhysicsState character_physics_state = start;
    auto interpolated_position = glm_utils::linearly_interpolate(j2g(start.position), j2g(end.position), t);
    auto interpolated_velocity = glm_utils::linearly_interpolate(j2g(start.velocity), j2g(end.velocity), t);
    character_physics_state.position = g2j(interpolated_position);
    character_physics_state.velocity = g2j(interpolated_velocity);
    return character_physics_state;
}

IdTaggedCharacterPhysicsState interpolate(IdTaggedCharacterPhysicsState start, IdTaggedCharacterPhysicsState end,
                                          float t) {

    IdTaggedCharacterPhysicsState interpolated_id_tagged_character_physics_state = start;

    interpolated_id_tagged_character_physics_state.character_physics_state =
        interpolate(start.character_physics_state, end.character_physics_state, t);

    return interpolated_id_tagged_character_physics_state;
}

GameState interpolate(GameState start, GameState end, float t) {
    GameState interpolated_game_state = start;

    // We only interpolate the enemy.
    interpolated_game_state.target_physics_state = interpolate(start.target_physics_state, end.target_physics_state, t);

    return interpolated_game_state;
}
