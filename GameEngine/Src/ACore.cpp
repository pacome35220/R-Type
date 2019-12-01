/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
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

void ACore::addToDeletionQueue(AEntityPtr entity) {
    this->deletionQueue.push_back(entity);
}

void ACore::addToDeletionQueue(std::size_t id) {
    this->addToDeletionQueue(this->getEntityFromId(id));
}
