/**
 * @file      Include/Client.hpp
 */

#pragma once

#include <SFML/Network/IpAddress.hpp>
#include <SFML/Window/Keyboard.hpp>

/**
 * @struct Client "Include/Client.hpp"
 * @brief This is the implementation of each client in the server
 */
struct Client {
    sf::IpAddress ip;
    unsigned short port;
    int keyMap[sf::Keyboard::KeyCount];
};
