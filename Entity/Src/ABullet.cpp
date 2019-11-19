/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** ABullet.cpp
*/

#include "ABullet.hpp"

ABullet::ABullet(const sf::Vector2f &position, ACore &entryPoint,
                 enum EntityID type, float amplitude, float counter)
    : AEntity(position, entryPoint, type) {
    this->amplitude = amplitude;
    this->counter = counter;
    this->originalY = position.y;
}

void ABullet::update() {
    if (position.x < -110 || position.x > 110 || position.y < -130 ||
        position.y > 130) {
        this->entryPoint.addToDeletionQueue(this->getId());
    }
    this->updateBullet();
}

void ABullet::onCollision(AEntityPtr entity) {
    (void)entity;
}
