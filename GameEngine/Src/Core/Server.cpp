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

void Core::Server::run()
{
    sf::Clock clock;
    size_t currentTotal = clock.getElapsedTime().asMicroseconds();
    size_t lastTotal = clock.getElapsedTime().asMicroseconds();
    static sf::Mutex mutex;

    while(true) {
		mutex.lock();
        currentTotal = clock.getElapsedTime().asMicroseconds();
        if (currentTotal - lastTotal >= 1000000 / this->frameRate) {
            clock.restart();
            this->updateEntities();
            this->procTopQueue();
            this->procDeletionQueue();
            this->action->flush();
            this->network->streamInput(this->action);
            bool tmp = this->canFeed;
            this->canFeed = true;
            this->network->readSocket(*this);
            this->canFeed = tmp;
            lastTotal = currentTotal;
		}
		mutex.unlock();
	}
    this->network->endOfStream();
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
