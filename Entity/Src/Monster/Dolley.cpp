/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** Dolley.cpp
*/

#include "Monster/Dolley.hpp"

#define HEALTH 150

Monster::Dolley::Dolley(ACore &entryPoint, sf::Vector2f &position, float speed, float amplitude,
                        float amplitudeSpeed) : AMonster(entryPoint, position, "./Assets/Sprites/Dolley.png", HEALTH, speed, amplitude, amplitudeSpeed, MonsterTypes::MT_DOLLEY_MONSTER)
{

}

Monster::Dolley::~Dolley() = default;

