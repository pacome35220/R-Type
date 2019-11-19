/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** Speed.cpp
*/

#include "Monster/Speed.hpp"

#define HEALTH 5

Monster::Speed::Speed(ACore &entryPoint, sf::Vector2f &position, float speed, float amplitude,
                      float amplitudeSpeed) : AMonster(entryPoint, position, "./Assets/Sprites/Monster/Speed.png", HEALTH, speed, amplitude, amplitudeSpeed, MonsterTypes::MT_SPEED_MONSTER)
{

}

Monster::Speed::~Speed() = default;

