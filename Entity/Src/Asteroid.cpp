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
        (enum EntityID)(EI_ASTEROID + rand() % 7 + 1)) {
    this->target.x = -90;
    this->target.y = rand() % 150 - 75;
}

AEntityPtr Asteroid::createAsteroidFromPacket(ACore &core, sf::Packet packet) {
    sf::Vector2f pos;
    sf::Uint64 id;

    packet >> id >> pos.x >> pos.y;

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
        this->health -= 10;
        entryPoint.addToDeletionQueue(entity);
    }
}

void Asteroid::update() {
	double deltaX = std::abs(this->originalPos.x + this->target.x);
	double deltaY = std::abs(this->originalPos.y + this->target.y);

    this->position.x -= 1;
    this->position.y += (deltaY / deltaX);
    if (this->position.x < -110) {
        this->position.x = 110;
        this->position.y = rand() % 50 - 100;
    }
    if (this->health < 0) {
        this->entryPoint.addToDeletionQueue(this->getId());
        this->entryPoint.feedEntity(std::make_shared<Asteroid>(sf::Vector2f(100, 0), entryPoint));
    }
    if (rand() % 2000 == 5)
        this->entryPoint.feedEntity(std::make_shared<Asteroid>(sf::Vector2f(100, 0), entryPoint));
}

void Asteroid::increaseStreamTimer() {
    streamTimer += 15;
}
