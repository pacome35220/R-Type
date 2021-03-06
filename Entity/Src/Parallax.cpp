/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** Parallax.cpp
*/

#include "Parallax.hpp"

Parallax::Parallax(ACore &core, sf::Vector2f pos): AEntity(pos, core, EI_PARALLAX) {
    this->lastTotal = 0;
    this->id = -1; // MDRRRRRRRRR
}

AEntityPtr Parallax::createParallaxFromPacket(ACore &core, sf::Packet packet) {
    sf::Vector2f pos;

    packet >> pos.x >> pos.y;
    return std::make_shared<Parallax>(core, pos);
}

void Parallax::onCollision(AEntityPtr entity) {
    (void) entity;
}

void Parallax::update() {
    this->currentTotal = this->clock.getElapsedTime().asMicroseconds();
    if (this->currentTotal - this->lastTotal >= 1000000 / 60) {
        this->clock.restart();
        if (this->position.x <= -200)
            this->position.x = 0;
        else
            this->position.x -= 1;
        this->lastTotal = this->currentTotal;
    }
}
