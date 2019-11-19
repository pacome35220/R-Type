/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** Monster.cpp
*/

#include "Bullet/Monster.hpp"

Bullet::Monster::Monster(const sf::Vector2f &position, ACore &entryPoint)
    : ABullet(position, "./Assets/Sprites/MonstersBullet.png", entryPoint,
              EL_MONSTER_BULLET) {}

void Bullet::Monster::updateBullet() {}
