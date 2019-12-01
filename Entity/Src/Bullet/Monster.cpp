/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** Monster.cpp
*/

#include <iostream>
#include "Bullet/Monster.hpp"

Bullet::Monster::Monster(const sf::Vector2f &position, ACore &entryPoint)
    : ABullet(position, entryPoint, EI_MONSTER_BULLET) {}

void Bullet::Monster::updateBullet() {
    this->position.x -= 4;
}

AEntityPtr Bullet::Monster::createMonsterFromPacket(ACore &core,
                                                    sf::Packet packet) {
    sf::Vector2f pos;
    sf::Uint64 id;

    packet >> id >> pos.x >> pos.y;

    std::cout << "Bullet::Monster::createMonsterFromPacket " << std::endl <<
        "\t" << "id: " << id << std::endl <<
        "\t" << "pos.x: " << pos.x << std::endl <<
        "\t" << "pos.y: " << pos.y << std::endl;

    auto tmp = std::make_shared<Monster>(pos, core);

    tmp->setId(id);
    return tmp;
}
