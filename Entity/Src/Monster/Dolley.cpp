/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** Dolley.cpp
*/

#include "Monster/Dolley.hpp"

#define HEALTH 150

Monster::Dolley::Dolley(ACore &entryPoint, const sf::Vector2f &position)
    : AMonster(position, entryPoint, EI_DOLLEY_MONSTER, 0.3, 3, 0.05, 0.3) {}
