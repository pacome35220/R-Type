/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** Asteroid.cpp
*/

#include <cmath>
#include <iostream>
#include "Asteroid.hpp"

Asteroid::Asteroid(sf::Vector2f position, ACore &core) : AEntity(position, core,
        (enum EntityID)(EI_ASTEROID + rand() % 8 + 1)) {

}

AEntityPtr Asteroid::createAsteroidFromPacket(ACore &core, sf::Packet packet) {
    sf::Vector2f pos;
    sf::Uint64 id;
    int entity;

    packet >> entity >> id >> pos.x >> pos.y;

    std::cout << "Asteroid::createAsteroidFromPacket " << std::endl <<
    "\t" << "id: " << id << std::endl <<
    "\t" << "pos.x: " << pos.x << std::endl <<
    "\t" << "pos.y: " << pos.y << std::endl;

    auto tmp = std::make_shared<Asteroid>(pos, core);

    tmp->setId(id);
    return tmp;
}

void Asteroid::onCollision(AEntityPtr entity) {
    if (entity->getEntityType() == EI_PLAYER_BULLET) {
        this->health--;
        entryPoint.addToDeletionQueue(getId());
    }
}

void Asteroid::update() {
    this->position.x -= 1;
    double deltaY = originalPos.y + target.y;
    double deltaX = originalPos.x + target.x;
    this->position.y += (deltaY / deltaX);

    if (this->position.x < -110) {
        this->position.x = 110;
        this->position.y = rand() % 50 - 100;
    }
    if (this->health < 0) {
        this->position.x = 110;
        this->position.y = rand() % 50 - 100;
        this->entryPoint.feedEntity(std::make_shared<Asteroid>(position, entryPoint));
        this->entryPoint.addToDeletionQueue(getId());
    }
}

void Asteroid::increaseStreamTimer() {
    streamTimer += 15;
}
