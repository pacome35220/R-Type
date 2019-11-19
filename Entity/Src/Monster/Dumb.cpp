/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** Dumb.cpp
*/

#include "Monster/Dumb.hpp"

#define HEALTH 10

Monster::Dumb::Dumb(ACore &entryPoint, const sf::Vector2f &position)
    : AMonster(position, "./Assets/Sprites/Monster/Dumb.png", entryPoint,
               EL_DUMB_MONSTER) {}
