/*
** EPITECH PROJECT, 2019
** for_norme
** File description:
** CoreServer.cpp
*/

#include <iostream>
#include "Core/Server.hpp"
#include "Player.hpp"

Core::Server::Server() {
    this->network = std::make_shared<Manager::Network>();
    this->resource = std::make_shared<Manager::Resource>();
}

void Core::Server::run()
{
    sf::Clock clock;
    size_t currentTotal = clock.getElapsedTime().asMicroseconds();
    size_t lastTotal = clock.getElapsedTime().asMicroseconds();
    static sf::Mutex mutex;

    while (true) {
		mutex.lock();
        currentTotal = clock.getElapsedTime().asMicroseconds();
        if (currentTotal - lastTotal >= 1000000 / this->frameRate) {
            clock.restart();
            this->updateEntities();
            this->procTopQueue();
            this->procDeletionQueue();
            // call function to handle collision
            this->network->readSocket(*this);
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