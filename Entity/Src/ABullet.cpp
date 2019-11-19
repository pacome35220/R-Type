/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** ABullet.cpp
*/

#include "ABullet.hpp"

ABullet::ABullet(const sf::Vector2f &position, const std::string &texturePath,
                 ACore &entryPoint, enum EntityID type)
    : AEntity(position, texturePath, entryPoint, type) {}

void ABullet::update() {
    if (position.x < -110 || position.x > 110 || position.y < -130 ||
        position.y > 130) {
        this->entryPoint.addToDeletionQueue(this->type);
    }
    this->updateBullet();
}

void ABullet::onCollision(AEntityPtr entity){};
