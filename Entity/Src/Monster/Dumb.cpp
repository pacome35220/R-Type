/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** Dumb.cpp
*/

#include "Monster/Dumb.hpp"

#define HEALTH 10

Monster::Dumb::Dumb(ACore &entryPoint, sf::Vector2f &position, float speed, float amplitude,
                    float amplitudeSpeed) : AMonster(entryPoint, position, "./Assets/Sprites/Monster/Dumb.png", HEALTH, speed, amplitude, amplitudeSpeed, MonsterTypes::MT_DUMB_MONSTER)
{

}

Monster::Dumb::~Dumb() = default;
