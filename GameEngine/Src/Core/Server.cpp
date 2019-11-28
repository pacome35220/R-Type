/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** Server.cpp
*/

#include <iostream>
#include "Core/Server.hpp"
#include "Player.hpp"

Core::Server::Server() {}

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
            this->collision->detectCollision(this->entities);
            this->network->readSocket(*this);
            lastTotal = currentTotal;
		}
		mutex.unlock();
	}
    this->network->endOfStream();
}

/**
 * updateEntities call `update` method of each entities.
 * When streamTime reach 15, updateEntities send to each clients
 * the new entity with PT_ENTITY_UPDATE event.
 */
void Core::Server::updateEntities() {
    for (std::size_t i = 0; i < this->entities.size(); i++) {
        this->entities[i]->update(); // this call change this->entities.size() so foreach is impossible
        if (this->entities[i]->getStreamTimer() >= 15) {
            this->entities[i]->resetStreamTimer();
            this->network->execEntityAction(this->entities[i], network::PT_ENTITY_UPDATE);
        } else
            this->entities[i]->increaseStreamTimer();
    }
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

void Core::Server::feedEntity(AEntityPtr entity) {
    std::cout << "Server::feedEntity " << entity->getEntityType() << std::endl;
    this->entities.push_back(entity);
    this->network->execEntityAction(entity, network::PacketType::PT_ENTITY_CREATION);
}
