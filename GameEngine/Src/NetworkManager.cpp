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

