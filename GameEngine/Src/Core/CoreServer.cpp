/*
** EPITECH PROJECT, 2019
** for_norme
** File description:
** CoreServer.cpp
*/

#include <iostream>
#include "Core/CoreServer.hpp"

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

void CoreServer::feedEntity(AEntityPtr entity) {
    networkManager->execEntityAction(entity, network::PT_ENTITY_CREATION);
    if (this->canFeed)
        this->entities.push_back(entity);
}

void CoreServer::run() {
    std::cout << "hey Server !" << std::endl;
    // TOOD
}

void CoreServer::renderEntities() {
    for (auto const &entity : this->entities)
        entity->render();
}

void CoreServer::procDelectionQueue() {
    for (const auto &entityToDelete : this->deletionQueue) {
        this->networkManager->execEntityAction(entityToDelete,
                                               network::PT_ENTITY_DESTRUCTION);
        auto tmp = std::find(this->entities.begin(), this->entities.end(),
                             entityToDelete);
        if (tmp != this->entities.end())
            this->entities.erase(tmp);
    }
    this->deletionQueue = std::vector<AEntityPtr>();
}
