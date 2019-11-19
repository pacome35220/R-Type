/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** Angry.cpp
*/

#include "Monster/Angry.hpp"

#define HEALTH 60

Monster::Angry::Angry(ACore &entryPoint, const sf::Vector2f &position)
    : AMonster(position, "./Assets/Sprites/Monster/Angry.png", entryPoint,
               EL_ANGRY_MONSTER) {}
