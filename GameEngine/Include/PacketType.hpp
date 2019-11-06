/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** PacketType.hpp
*/

#pragma once

namespace network {
    enum PACKET_TYPE {
        PT_PORT_REDIRECTION,
        PT_PLAYER_JOIN,
        PT_ENTITY_CREATION,
        PT_ENTITY_UPDATE,
        PT_ENTITY_DESTRUCTION,
        PT_STREAM_END,
        PT_INPUT
    };
};