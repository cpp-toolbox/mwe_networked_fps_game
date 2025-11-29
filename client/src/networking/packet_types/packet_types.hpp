#ifndef PACKET_TYPES_HPP
#define PACKET_TYPES_HPP

#include <cstdint>

enum class PacketType : uint8_t { CLIENT_UPDATE_DATA, GAME_STATE, NUM_ENUMERATORS };

#endif // PACKET_TYPES_HPP
