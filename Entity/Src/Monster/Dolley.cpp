/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** Dolley.cpp
*/

#include "PowerUp.hpp"
#include "Monster/Dolley.hpp"

Monster::Dolley::Dolley(ACore &entryPoint, const sf::Vector2f &position)
    : AMonster(position, entryPoint, EI_DOLLEY_MONSTER, 0.3, 3, 0.05, 0.3) {}

void Monster::Dolley::updateMonster() {
    if (this->health < 0) {
        this->entryPoint.addToDeletionQueue(this->getId());
        this->entryPoint.feedEntity(
            std::make_shared<PowerUp>(this->entryPoint, sf::Vector2f(100, 0)));
    }
}
