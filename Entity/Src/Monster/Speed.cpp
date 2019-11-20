/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** Speed.cpp
*/

#include "Monster/Speed.hpp"

#define HEALTH 5

Monster::Speed::Speed(ACore &entryPoint, const sf::Vector2f &position, float scale)
    : AMonster(position, entryPoint, EI_SPEED_MONSTER, 1, 5, 0.03, scale) {}
