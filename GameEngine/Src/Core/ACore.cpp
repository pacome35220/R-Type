/*
** EPITECH PROJECT, 2019
** for_norme
** File description:
** ACore.cpp
*/

#include "ACore.hpp"

ACore::ACore() : frameRate(60) {}

/**
 * Setter
 */

void ACore::setAction(std::shared_ptr<Manager::Action> action)
{
    this->action = action;
}
void ACore::setCollision(std::shared_ptr<Manager::Collision> collision)
{
    this->collision = collision;
}
void ACore::setNetwork(std::shared_ptr<Manager::Network> network)
{
    this->network = network;
}
void ACore::setAudio(std::shared_ptr<Manager::Audio> audio)
{
    this->audio = audio;
}

/**
 * Getter
 */

std::shared_ptr<Manager::Audio> ACore::getAudio() const
{
    return this->audio;
}
std::shared_ptr<Manager::Action> ACore::getAction() const
{
    return this->action;
}
std::shared_ptr<Manager::Network> ACore::getNetwork() const
{
    return this->network;
}
std::shared_ptr<Manager::Collision> ACore::getCollision() const
{
    return this->collision;
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
        if (entity->getStreamTimer() >= 15) {
            entity->resetStreamTimer();
            this->network->execEntityAction(entity, network::PT_ENTITY_UPDATE);
        } else
            entity->incStreamTimer();
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

void ACore::feedEntity(AEntityPtr entity) {
    this->entities.push_back(entity);
    this->network->execEntityAction(entity,
                                    network::PacketType::PT_ENTITY_CREATION);
}

void ACore::addToDeletionQueue(AEntityPtr entity) {
	this->deletionQueue.push_back(entity);
}

void ACore::addToDeletionQueue(enum EntityID entityId) {
    this->addToDeletionQueue(this->getEntityFromId(entityId));
}
