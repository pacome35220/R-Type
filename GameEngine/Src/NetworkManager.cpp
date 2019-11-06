/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** NetworkManager.cpp
*/

#include "NetworkManager.hpp"

NetworkManager::NetworkManager()
{
    // Todo
}
NetworkManager::~NetworkManager()
{
    // Todo
}
void NetworkManager::setIpTarget(const string &_ipTarget)
{
    NetworkManager::ipTarget = _ipTarget;
}
void NetworkManager::setPortTarget(uint16 _portTarget)
{
    NetworkManager::portTarget = _portTarget;
}
const vector<Client> &NetworkManager::getClients() const
{
    return clients;
}
void NetworkManager::bindSocket(uint16 _port)
{
    // Todo
}
void NetworkManager::sendPacket(Packet, IpAddress _ip, uint16 _port)
{
    // Todo
}
void NetworkManager::readSocket(ACore &core)
{
    // Todo
}
bool NetworkManager::isClientKeyPressed(int _clientId, Keyboard::Key _key)
{
    return false;
}
void NetworkManager::execEntityAction(AEntity *entity, network::PACKET_TYPE packetType)
{
    // Todo
}

