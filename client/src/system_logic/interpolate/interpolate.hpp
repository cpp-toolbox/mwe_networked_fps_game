#ifndef INTERPOLATE_HPP
#define INTERPOLATE_HPP

#include "../../networking/packets/packets.hpp"
#include "../../utility/glm_utils/glm_utils.hpp"
#include "../../utility/jolt_glm_type_conversions/jolt_glm_type_conversions.hpp"

CharacterPhysicsState interpolate(CharacterPhysicsState start, CharacterPhysicsState end, float t);
IdTaggedCharacterPhysicsState interpolate(IdTaggedCharacterPhysicsState start, IdTaggedCharacterPhysicsState end,
                                          float t);
GameState interpolate(GameState start, GameState end, float t);

#endif // INTERPOLATE_HPP
