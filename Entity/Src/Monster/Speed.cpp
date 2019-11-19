/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** Speed.cpp
*/

#include "Monster/Speed.hpp"

#define HEALTH 5

Monster::Speed::Speed(ACore &entryPoint, const sf::Vector2f &position)
    : AMonster(position, "./Assets/Sprites/Monster/Speed.png", entryPoint,
               EL_SPEED_MONSTER) {}
