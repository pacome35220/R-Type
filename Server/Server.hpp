/**
 * @file      Server/Server.hpp
 */

#pragma once

#include <vector>
#include <SFML/Network.hpp>
#include "Core/Server.hpp"

/**
 * @namespace Server
 * @brief Server methods
 * @details This namespace will provide all server's method.
 */
namespace Server {
    void start(unsigned short port);
    void entityFeeder(Core::Server &core);
    void threadEntryPoint(std::shared_ptr <sf::UdpSocket> socket);
}
