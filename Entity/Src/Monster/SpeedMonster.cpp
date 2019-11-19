#include "Monster/SpeedMonster.hpp"

#define HEALTH 5

SpeedMonster::SpeedMonster(ACore &entryPoint, sf::Vector2f &position, float speed, float amplitude, float amplitudeSpeed)
: Monster(entryPoint, position, "./Assets/Sprites/SpeedMonster.png", HEALTH, speed, amplitude, amplitudeSpeed, MonsterTypes::MT_SPEED_MONSTER)
{
}

SpeedMonster::~SpeedMonster()
{
}
