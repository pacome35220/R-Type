/*
** EPITECH PROJECT, 2019
** for_norme
** File description:
** ACore.cpp
*/

#include "Core/ACore.hpp"

ACore::ACore() : frameRate(60) {}

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

std::shared_ptr<CollisionManager> ACore::getCollisionManager() const {
    return this->collisionManager;
}

AEntityPtr ACore::getEntityFromId(size_t id) {
    for (const auto &entity : entities)
        if (entity->getId() == id)
            return entity;
    return nullptr;
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
        for (std::size_t i = 0; i < this->entities.size(); i++) {
            if (this->entities[i]->getId() == value) {
                auto tmp = this->entities[i];
                this->entities.erase(this->entities.begin() + i);
                this->entities.push_back(tmp);
                return;
            }
        }
    }
    this->topQueue = std::vector<std::size_t>();
}
