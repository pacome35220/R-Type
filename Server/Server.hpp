/**
 * @file      server.hpp
 * @brief     This is the Server namespace
 * @details   This namespace will provide all server's method.
 */

#pragma once

#include <vector>
#include <SFML/Network.hpp>
#include "Core/CoreServer.hpp"

namespace Server
{
    void start(unsigned short port);
    void entityFeeder(CoreServer &core);
    void threadEntryPoint(unsigned short port);
}
