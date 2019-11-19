/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** Classic.cpp
*/

#include "Monster/Classic.hpp"

#define HEALTH 25

Monster::Classic::Classic(ACore &entryPoint, const sf::Vector2f &position)
    : AMonster(position, entryPoint, EL_CLASSIC_MONSTER) {}
