/**
 * @file      Client.hpp
 * @brief     This is the implementation of each client in the server
 */


#pragma once

#include <SFML/Network/IpAddress.hpp>
#include <SFML/Window/Keyboard.hpp>

using namespace sf;

typedef unsigned short uint16;

/**
 * @class Client Client.hpp "Include/Client.hpp"
 */
class Client
{
public:
    Client();
    Client(IpAddress ip, uint16 port);
    ~Client();
    const IpAddress &getIp() const;
    void setIp(const IpAddress &ip);
    uint16 getPort() const;
    void setPort(uint16 port);
    const int *getKeyMap() const;

private:
    IpAddress ip;
    uint16 port;
    int keyMap[Keyboard::KeyCount];
};
