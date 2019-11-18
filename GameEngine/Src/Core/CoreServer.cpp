/*
** EPITECH PROJECT, 2019
** for_norme
** File description:
** CoreServer.cpp
*/

#include <iostream>
#include "Core/CoreServer.hpp"
#include "Error.hpp"

CoreServer::CoreServer() {}

// void CoreServer::addEntity(AEntityPtr entity)
// {
//     ACore::addEntity(move(entity));
//     // TODO send to clients
// }

// void CoreServer::removeEntity(AEntityPtr entity)
// {
//     ACore::removeEntity(move(entity));
//     // TODO send to clients
// }

void CoreServer::run() {
    std::cout << "hey Server !" << std::endl;
    // TODO
}

void CoreServer::onPlayerJoin(const sf::IpAddress &senderIp,
                              unsigned short senderPort) {
    sf::Vector2i newClientPosition(-90, 0);
    std::size_t newClientID = this->network->getClients().size();

    // this->addEntity(std::make_unique<Player>(newClientPosition, newClientID));
    network->addNewClient(senderIp, senderPort);
}

void CoreServer::procDelectionQueue() {
    for (const auto &entityToDelete : this->deletionQueue) {
        this->network->execEntityAction(entityToDelete,
                                        network::PT_ENTITY_DESTRUCTION);
        auto tmp = std::find(this->entities.begin(), this->entities.end(),
                             entityToDelete);
        if (tmp != this->entities.end())
            this->entities.erase(tmp);
    }
    this->deletionQueue = std::vector<AEntityPtr>();
}
