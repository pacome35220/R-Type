/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** Monster.cpp
*/

#include "Bullet/Monster.hpp"

Bullet::Monster::Monster(const sf::Vector2f &position, ACore &entryPoint,
                         float _amplitude, int _count)
    : ABullet(position, "./Assets/Sprites/MonstersBullet.png", entryPoint,
              EL_MONSTER_BULLET, _amplitude, _count) {}

void Bullet::Monster::updateBullet() {
    this->counter += 0.2;
    this->position.x -= 4;
}
