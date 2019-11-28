/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** Monster.cpp
*/

#include <iostream>
#include "Bullet/Monster.hpp"

Bullet::Monster::Monster(const sf::Vector2f &position, ACore &entryPoint,
                         float _amplitude, int _count)
    : ABullet(position, entryPoint, EI_MONSTER_BULLET, _amplitude, _count) {}

void Bullet::Monster::updateBullet() {
    this->counter += 0.2;
    this->position.x -= 4;
}


AEntityPtr Bullet::Monster::createMonsterFromPacket(ACore &core, sf::Packet packet)
{
    sf::Vector2f pos;
    float amplitude;
    int counter;
    sf::Uint64 id;
    int entity;

    packet >> entity >> id >> pos.x >> pos.y >> amplitude >> counter;
    std::cout << "Monster::createMonsterFromPacket " << std::endl <<
    "\t" << "id: " << id << std::endl <<
    "\t" << "pos.x: " << pos.x << std::endl <<
    "\t" << "pos.y: " << pos.y << std::endl <<
    "\t" << "amplitude: " << amplitude << std::endl <<
    "\t" << "counter: " << counter << std::endl;

    auto tmp = std::make_shared<Monster>(pos, core, amplitude, counter);

    tmp->setId(id);
    return tmp;
}
