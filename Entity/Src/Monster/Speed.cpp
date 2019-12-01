/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** Speed.cpp
*/

#include "Monster/Speed.hpp"

Monster::Speed::Speed(ACore &entryPoint, const sf::Vector2f &position,
                      float scale)
    : AMonster(position, entryPoint, EI_SPEED_MONSTER, 1, 5, 0.03, scale) {}

void Monster::Speed::onDeath() {
    this->entryPoint.addToDeletionQueue(this->getId());
    this->entryPoint.feedEntity(std::make_shared<Monster::Speed>(
        this->entryPoint, sf::Vector2f(100, 0), this->scale));
}
