/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** Classic.cpp
*/

#include "Monster/Classic.hpp"

#define HEALTH 25

Monster::Classic::Classic(ACore &entryPoint, sf::Vector2f &position, float speed, float amplitude,
                          float amplitudeSpeed) : AMonster(entryPoint, position, "./Assets/Sprites/Monster/Classic.png", HEALTH, speed, amplitude, amplitudeSpeed, MonsterTypes::MT_SPEED_MONSTER)
{

}

Monster::Classic::~Classic() = default;
