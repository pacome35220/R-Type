/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** DeathStar.cpp
*/

#include <iostream>
#include "Bullet/DeathStar.hpp"

Bullet::DeathStar::DeathStar(const sf::Vector2f &position, ACore &entryPoint,
                             float _amplitude, int _counter)
    : ABullet(position, entryPoint, EI_DEATH_STAR_BULLET, _amplitude, _counter) {}

void Bullet::DeathStar::updateBullet() {
    this->position.y += this->amplitude * 2.5;
}

AEntityPtr Bullet::DeathStar::createDeathStarFromPacket(ACore &core, sf::Packet packet)
{
    sf::Vector2f pos;
    float amplitude;
    int counter;
    sf::Uint64 id;

    packet >> id >> pos.x >> pos.y >> amplitude >> counter;
    std::cout << "Bullet::DeathStar::createDeathStarFromPacket " << std::endl <<
    "\t" << "id: " << id << std::endl <<
    "\t" << "pos.x: " << pos.x << std::endl <<
    "\t" << "pos.y: " << pos.y << std::endl <<
    "\t" << "amplitude: " << amplitude << std::endl <<
    "\t" << "counter: " << counter << std::endl;

    auto tmp = std::make_shared<DeathStar>(pos, core, amplitude, counter);

    tmp->setId(id);
    return tmp;
}
