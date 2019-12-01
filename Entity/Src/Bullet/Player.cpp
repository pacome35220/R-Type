/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** Bullet/Player.cpp
*/

#include <cmath>
#include <iostream>
#include "Bullet/Player.hpp"

Bullet::Player::Player(const sf::Vector2f &position, ACore &entryPoint,
                       float _amplitude): ABullet(position, entryPoint,
                                                  EI_PLAYER_BULLET, _amplitude,
                                                  M_PI_2) {}

void Bullet::Player::updateBullet() {
    this->counter += 0.2;
    this->position.x += 4;
    this->position.y = this->originalY
                       + cos(this->counter) * 10 * this->amplitude;
}

AEntityPtr Bullet::Player::createPlayerFromPacket(ACore &core, sf::Packet
                                                    packet) {
    sf::Vector2f pos;
    float amplitude;
    sf::Uint64 id;

    packet >> id >> pos.x >> pos.y >> amplitude;
    std::cout << "Player::createPlayerFromPacket " << std::endl << "\t"
              << "id: " << id << std::endl << "\t" << "pos.x: " << pos.x
              << std::endl << "\t" << "pos.y: " << pos.y << std::endl << "\t"
              << "amplitude: " << amplitude << std::endl;
    auto tmp = std::make_shared<Player>(pos, core, amplitude);

    tmp->setId(id);
    return tmp;
}
