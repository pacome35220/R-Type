/**
 * @file      PacketType.hpp
 */

#pragma once

/**
 * @namespace network  "Include/PacketType.hpp"
 * @brief This is the enumeration of the packets types.
 * @details This enumeration regroup all types used in the code.
 */
namespace network {
    enum PacketType {
        PT_PORT_REDIRECTION,
        PT_PLAYER_JOIN,
        PT_ENTITY_CREATION,
        PT_ENTITY_UPDATE,
        PT_ENTITY_DESTRUCTION,
        PT_STREAM_END,
        PT_INPUT
    };
}