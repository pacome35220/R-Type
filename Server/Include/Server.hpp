/**
 * @file      server.hpp
 * @brief     This is the Server namespace
 * @details   This namespace will provide all server's method.
 */

#pragma once

#include <vector>
#include <SFML/Network.hpp>
#include "ACore.hpp"

namespace Server 
{
    void start(unsigned short port);
    void entityFeeder(ACore &core);
    void threadEntryPoint(unsigned short port);
    void onPlayerJoin(ACore &core, const sf::ipAddress &senderIP, const unsigned short &senderPort);
}