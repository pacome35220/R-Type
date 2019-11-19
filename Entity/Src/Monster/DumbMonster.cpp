#include "Monster/DumbMonster.hpp"

#define HEALTH 10

DumbMonster::DumbMonster(ACore &entryPoint, sf::Vector2f &position, float speed, float amplitude, float amplitudeSpeed)
: Monster(entryPoint, position, "./Assets/Sprites/DumbMonster.png", HEALTH, speed, amplitude, amplitudeSpeed, MonsterTypes::MT_DUMB_MONSTER)
{
}

DumbMonster::~DumbMonster()
{
}
