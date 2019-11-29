/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** PowerUp.cpp
*/

#include "PowerUp.hpp"

PowerUp::PowerUp(ACore &core, const sf::Vector2f &position)
    : AEntity(position, core, EntityID::EI_POWER_UP) {}

void PowerUp::onCollision(AEntityPtr entity) {
    if (entity->getEntityType() == EntityID::EI_DEATH_STAR) {
        health--;
        entryPoint.addToDeletionQueue(getId());
    }
}

void PowerUp::update() {
    position.x -= 0.1;
}
