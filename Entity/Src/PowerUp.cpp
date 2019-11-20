/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** PowerUp.cpp
*/

#include "PowerUp.hpp"

PowerUp::PowerUp(ACore &core, sf::Vector2f &position) : AEntity(position, core, EntityID::EI_POWER_UP) {

}

PowerUp::~PowerUp() = default;

void PowerUp::onCollision(AEntityPtr entity)
{
    if (getEntityType() == EntityID::EI_DEATH_STAR) {
        health--;
        entryPoint.addToDeletionQueue(getId());
    }
}

void PowerUp::update() {
    position.x -= 0.1;
}
