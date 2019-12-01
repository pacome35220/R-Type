/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** Angry.cpp
*/

#include "Monster/Angry.hpp"

Monster::Angry::Angry(ACore &entryPoint, const sf::Vector2f &position,
                      float scale)
    : AMonster(position, entryPoint, EI_ANGRY_MONSTER, 0.1, 0.2, 0.01, scale) {}

void Monster::Angry::onDeath() {
    this->entryPoint.addToDeletionQueue(this->getId());
    this->entryPoint.feedEntity(std::make_shared<Monster::Angry>(
        this->entryPoint, sf::Vector2f(100, 0), this->scale));
}
