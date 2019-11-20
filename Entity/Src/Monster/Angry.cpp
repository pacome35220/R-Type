/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** Angry.cpp
*/

#include "Monster/Angry.hpp"

#define HEALTH 60

Monster::Angry::Angry(ACore &entryPoint, const sf::Vector2f &position, float scale)
    : AMonster(position, entryPoint, EI_ANGRY_MONSTER,  0.1, 0.2, 0.01, scale) {}
