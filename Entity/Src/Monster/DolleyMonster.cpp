#include "Monster/DolleyMonster.hpp"

#define HEALTH 150

DolleyMonster::DolleyMonster(ACore *entryPoint, sf::Vector2f &position, float speed, float amplitude, float amplitudeSpeed)
: Monster(entryPoint, position, "./Assets/Sprites/DolleyMonster.png", HEALTH, speed, amplitude, amplitudeSpeed, monsterTypes::MT_DOLLEY_MONSTER)
{
}

DolleyMonster::~DolleyMonster()
{
}
