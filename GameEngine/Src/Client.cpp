/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** Client.cpp
*/

#include "Client.hpp"

/*
 *   Constructors // Destructor
*/
Client::Client()
{
    // TODO
}
Client::Client(IpAddress _ip, uint16 _port)
{
    // TODO
    ip = _ip;
    port = _port;
}
Client::~Client()
{
    // TODO
}
/*
 *   Getters // Setters
*/
const IpAddress &Client::getIp() const
{
    return ip;
}
void Client::setIp(const IpAddress &ip)
{
    Client::ip = ip;
}
uint16 Client::getPort() const
{
    return port;
}
void Client::setPort(uint16 port)
{
    Client::port = port;
}
const int *Client::getKeyMap() const
{
    return keyMap;
}


