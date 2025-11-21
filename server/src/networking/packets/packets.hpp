#ifndef PACKETS_HPP
#define PACKETS_HPP

#include "../../sound/sound_types/sound_types.hpp"
#include "../../system_logic/data_to_reconstruct_client_game_state_when_firing_on_server/data_to_reconstruct_client_game_state_when_firing_on_server.hpp"
#include "../../system_logic/reconciliation_types/reconciliation_types.hpp"
#include "../packet_data/packet_data.hpp"
#include "../packet_types/packet_types.hpp"

#include <glm/glm.hpp>

struct SuccessfullyConnected {
  unsigned int client_id = 0;
};

struct SuccessfullyConnectedPacket {
  PacketHeader packet_header;
  SuccessfullyConnected successfully_connected;
};

struct ClientUpdateData {
  unsigned int id;
  std::vector<CharacterUpdateDataTimeBundle> character_update_data_time_bundles;
};

struct ClientUpdateDataPacket {
  PacketHeader packet_header;
  ClientUpdateData client_update_data;
};

struct GameState {
  unsigned int id;
  IdTaggedCharacterPhysicsState id_tagged_character_physics_state;
  IdTaggedCharacterCameraState id_tagged_character_camera_state;
  CharacterPhysicsState target_physics_state;
  std::vector<SoundType> sounds;
};

struct GameStatePacket {
  PacketHeader packet_header;
  GameState game_state;
};

#endif // PACKETS_HPP
