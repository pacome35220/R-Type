/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** DeathStar.cpp
*/

#include "Bullet/DeathStar.hpp"

Bullet::DeathStar::DeathStar(const sf::Vector2f &position, ACore &entryPoint,
                             float _amplitude, int _count)
    : ABullet(position, entryPoint, EI_DEATH_STAR_BULLET, _amplitude, _count) {}

void Bullet::DeathStar::updateBullet() {
    this->position.y += this->amplitude * 2.5;
}
