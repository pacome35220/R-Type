/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** Angry.cpp
*/

#include "Monster/Angry.hpp"

#define HEALTH 60

Monster::Angry::Angry(ACore &entryPoint, sf::Vector2f &position, float speed, float amplitude,
                      float amplitudeSpeed) : AMonster(entryPoint, position, "./Assets/Sprites/Monster/Angry.png", HEALTH, speed, amplitude, amplitudeSpeed, MonsterTypes::MT_SPEED_MONSTER)
{

}

Monster::Angry::~Angry() = default;
