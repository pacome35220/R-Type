/*
** EPITECH PROJECT, 2019
** for_norme
** File description:
** CoreServer.cpp
*/

#include <iostream>
#include "Core/Server.hpp"
#include "Player.hpp"

Core::Server::Server() {}

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

void Core::Server::run() {
    std::cout << "hey Server !" << std::endl;
    // TODO
}

void Core::Server::procDeletionQueue() {
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
