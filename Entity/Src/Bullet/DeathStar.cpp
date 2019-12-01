/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** DeathStar.cpp
*/

#include <iostream>
#include "Bullet/DeathStar.hpp"

Bullet::DeathStar::DeathStar(const sf::Vector2f &position, ACore &entryPoint,
                             float _amplitude)
    : ABullet(position, entryPoint, EI_DEATH_STAR_BULLET, _amplitude) {}

void Bullet::DeathStar::updateBullet() {
    this->position.y += this->amplitude * 2.5;
}

sf::Packet Bullet::DeathStar::buildMyAsAPacket(network::PacketType packetType) {
    sf::Packet packet = AEntity::buildMyAsAPacket(packetType);

    packet << this->amplitude;
    std::cout << "Bullet::DeathStar::buildMyAsAPacket" << std::endl <<
        "\t" << "this->amplitude: " << this->amplitude << std::endl;

    return packet;
}

AEntityPtr Bullet::DeathStar::createDeathStarFromPacket(ACore &core,
                                                        sf::Packet packet) {
    sf::Vector2f pos;
    float amplitude;
    sf::Uint64 id;

    packet >> id >> pos.x >> pos.y >> amplitude;

    std::cout << "Bullet::DeathStar::createDeathStarFromPacket " << std::endl <<
        "\t" << "id: " << id << std::endl <<
        "\t" << "pos.x: " << pos.x << std::endl <<
        "\t" << "pos.y: " << pos.y << std::endl <<
        "\t" << "amplitude: " << amplitude << std::endl;

    auto tmp = std::make_shared<DeathStar>(pos, core, amplitude);

    tmp->setId(id);
    return tmp;
}
