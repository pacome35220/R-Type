/*
** EPITECH PROJECT, 2019
** for_norme
** File description:
** ACore.cpp
*/

#include "Core/ACore.hpp"

void ACore::addEntity(AEntityPtr entity) {
    // entityMap[entity->getId()] = move(entity); // move ?
}

void ACore::removeEntity(AEntityPtr entity) {
    // entityMap.erase(entity->getId());
}

/**
 * Setter
 */

void ACore::setActionManager(std::shared_ptr<ActionManager> actionManager) {
    this->actionManager = actionManager;
}

void ACore::setCollisionManager(
    std::shared_ptr<CollisionManager> collisionManager) {
    this->collisionManager = collisionManager;
}

void ACore::setNetworkManager(std::shared_ptr<NetworkManager> networkManager) {
    this->networkManager = networkManager;
}

void ACore::setAudioManager(std::shared_ptr<AudioManager> audioManager) {
    this->audioManager = audioManager;
}

/**
 * Getter
 */

std::shared_ptr<AudioManager> ACore::getAudioManager() const {
    return this->audioManager;
}

std::shared_ptr<ActionManager> ACore::getActionManager() const {
    return this->actionManager;
}

std::shared_ptr<NetworkManager> ACore::getNetworkManager() const {
    return this->networkManager;
}

std::shared_ptr<CollisionManager> ACore::getPhysicManager() const {
    return this->collisionManager;
}

AEntityPtr ACore::getEntityFromId(size_t id) {
    for (const auto &entity : entities)
        if (entity->getId() == id)
            return entity;
    return nullptr;
}

void ACore::onPlayerJoin(const sf::IpAddress &senderIp,
                         unsigned short senderPort) {
    sf::Vector2f pos(-90, 0);
    // feedEntity(new Player(pos,
    // (int)core.getNetworkManager()->getClientVector().size()));
    for (const auto &value : networkManager->getClients())
        if (value.ip == senderIp && value.port == senderPort)
            return;
    networkManager->addNewClient(senderIp, senderPort);
}

void ACore::updateEntities() {
    for (auto &entity : this->entities) {
        entity->update();
        // if (entity->getStreamTimer() >= 15) {
        // 	entity->resetStreamTimer();
        // 	this->networkManager->execEntityAction(entity,
        // network::PT_ENTITY_UPDATE);
        // }
        // else
        // 	entity->incStreamTimer();
    }
}

void ACore::procTopQueue() {
    for (const auto &value : this->topQueue) {
        for (unsigned int j = 0; j < this->entities.size(); j++) {
            if (this->entities[j]->getId() == value) {
                auto tmp = this->entities[j];
                this->entities.erase(this->entities.begin() + j);
                this->entities.push_back(tmp);
                return;
            }
        }
    }
    this->topQueue = std::vector<int>();
}
