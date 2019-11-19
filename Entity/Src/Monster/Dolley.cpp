/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** Dolley.cpp
*/

#include "Monster/Dolley.hpp"

#define HEALTH 150

Monster::Dolley::Dolley(ACore &entryPoint, const sf::Vector2f &position)
    : AMonster(position, "./Assets/Sprites/Monster/Dolley.png", entryPoint,
               EL_DOLLEY_MONSTER) {}
