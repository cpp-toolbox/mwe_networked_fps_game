#ifndef UPDATE_PHYSICS_CHARACTER_HPP
#define UPDATE_PHYSICS_CHARACTER_HPP

#include <Jolt/Jolt.h>
#include <Jolt/Physics/Character/CharacterVirtual.h>

#include "../reconciliation_types/reconciliation_types.hpp"
#include "sbpt_generated_includes.hpp"

void update_physics_character(
    const CharacterPhysicsUpdateData &cpud,
    JPH::Ref<JPH::CharacterVirtual> &physics_character, Physics &physics);

#endif // UPDATE_PHYSICS_CHARACTER_HPP
