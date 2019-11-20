/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** Player.cpp
*/

#include <cmath>
#include "Bullet/Player.hpp"

Bullet::Player::Player(const sf::Vector2f &position, ACore &entryPoint,
                       float _amplitude)
    : ABullet(position, entryPoint, EI_PLAYER_BULLET, _amplitude, M_PI_2) {}

void Bullet::Player::updateBullet() {
    this->counter += 0.2;
    this->position.x += 4;
    this->position.y =
        this->originalY + cos(this->counter) * 10 * this->amplitude;
}
