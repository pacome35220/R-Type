/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** Core/Server.cpp
*/

#include <iostream>
#include "Core/Server.hpp"
#include "Player.hpp"

Core::Server::Server() {}

void Core::Server::run() {
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
            this->network->readSocket(*this);
            lastTotal = currentTotal;
        }
        mutex.unlock();
    }
    this->network->endOfStream();
}

/**
 * @brief updateEntities call `update` method of each entities.
 * When streamTime reach 15, updateEntities send to each clients
 * the new entity with PT_ENTITY_UPDATE event.
 */
void Core::Server::updateEntities() {
    for (std::size_t i = 0 ; i < this->entities.size() ; i++) {
        this->entities[i]->update(); // this call change this->entities.size() so foreach is impossible
        if (this->entities[i]->getStreamTimer() >= 15) {
            this->entities[i]->resetStreamTimer();
            this->network->execEntityAction(this->entities[i],
                                            network::PT_ENTITY_UPDATE);
        } else
            this->entities[i]->increaseStreamTimer();
    }
}

void Core::Server::procDeletionQueue() {
    for (std::size_t i = 0 ; i < this->deletionQueue.size() ; i++) {
        // for (const auto &entityToDelete : this->deletionQueue) {
        auto tmp = std::find(this->entities.begin(), this->entities.end(),
                             this->deletionQueue[i]);
        if (tmp != this->entities.end()) {
            this->network->execEntityAction(this->deletionQueue[i],
                                            network::PT_ENTITY_DESTRUCTION);
            this->entities.erase(tmp);
        }
    }
    this->deletionQueue = std::vector<AEntityPtr>();
}

/**
 * @brief Create an entity without a texture and insert it in the entities
 * vector
 * @details Actually, we don't need a texture on the server (no window)
 * @param entity
 */
void Core::Server::feedEntity(AEntityPtr entity) {
    std::cout << "Server::feedEntity " << entity->getEntityType() << std::endl;
    this->entities.push_back(entity);
    this->network->execEntityAction(entity,
                                    network::PacketType::PT_ENTITY_CREATION);
}
