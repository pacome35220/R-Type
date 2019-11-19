/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** ABullet.cpp
*/

#include "ABullet.hpp"
#include <utility>

ABullet::ABullet(ACore &entryPoint, enum EntityID type, sf::Vector2f &position,
                 std::string texturePath) : AEntity(position, std::move(texturePath), entryPoint, type)
{
    this->type = type;
}

ABullet::~ABullet() = default;

void ABullet::update()
{
    if (position.x < -110 || position.x > 110 || position.y < -130 || position.y > 130) {
        this->entryPoint.addToDeletionQueue(this->type);
    }
    this->updateBullet();
}
