/*
** EPITECH PROJECT, 2019
** for_norme
** File description:
** ACore.cpp
*/

#include "ACore.hpp"

ACore::ACore(): frameRate(60) {
    this->network = std::make_shared<Manager::Network>();
}

std::shared_ptr<Manager::Network> ACore::getNetwork() const {
    return this->network;
}

AEntityPtr ACore::getEntityFromId(std::size_t id) {
    for (const auto &entity : entities)
        if (entity->getId() == id)
            return entity;
    return nullptr;
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

void ACore::addToDeletionQueue(AEntityPtr entity) {
    this->deletionQueue.push_back(entity);
}

void ACore::addToDeletionQueue(std::size_t id) {
    this->addToDeletionQueue(this->getEntityFromId(id));
}
