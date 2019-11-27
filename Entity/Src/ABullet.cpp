/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** ABullet.cpp
*/

#include <iostream>
#include "ABullet.hpp"

ABullet::ABullet(const sf::Vector2f &position, ACore &entryPoint,
                 enum EntityID type, float amplitude, float counter)
    : AEntity(position, entryPoint, type) {
    this->amplitude = amplitude;
    this->counter = counter;
    this->originalY = position.y;
}

// AEntityPtr ABullet::createABulletFromPacket(ACore &core, sf::Packet packet)
// {
//     sf::Vector2f pos;
//     float amplitude;
//     float counter;
//     sf::Uint64 id;
//     int entity;

//     packet >> entity >> id >> pos.x >> pos.y >> amplitude >> counter;
//     std::cout << "ABullet::createABulletFromPacket " << std::endl <<
//     "\t" << "id: " << id << std::endl <<
//     "\t" << "pos.x: " << pos.x << std::endl <<
//     "\t" << "pos.y: " << pos.y << std::endl <<
//     "\t" << "amplitude: " << amplitude << std::endl <<
//     "\t" << "counter: " << counter << std::endl;

//     auto tmp = std::make_shared<ABullet>(pos, core, (EntityID) entity, amplitude, counter);

//     tmp->setId(id);
//     return tmp;
// }


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
