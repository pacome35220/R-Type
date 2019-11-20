/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** Dumb.cpp
*/

#include "Monster/Dumb.hpp"

#define HEALTH 10

Monster::Dumb::Dumb(ACore &entryPoint, const sf::Vector2f &position, float scale) //TODO check if scale really useful
    : AMonster(position, entryPoint, EI_DUMB_MONSTER, 0.3, 1, 0.01, scale) {}
