/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** Dumb.cpp
*/

#include "Monster/Dumb.hpp"

Monster::Dumb::Dumb(ACore &entryPoint, const sf::Vector2f &position,
                    float scale)
    : AMonster(position, entryPoint, EI_DUMB_MONSTER, 0.3, 1, 0.01, scale) {}

void Monster::Dumb::updateMonster() {
    if (this->health < 0) {
        this->entryPoint.addToDeletionQueue(this->getId());
        this->entryPoint.feedEntity(std::make_shared<Monster::Dumb>(
            this->entryPoint, sf::Vector2f(100, (std::rand() % 200) - 100),
            this->scale));
    }
}
