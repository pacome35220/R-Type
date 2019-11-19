#include "Monster/VenerMonster.hpp"

#define HEALTH 60

VenerMonster::VenerMonster(ACore &entryPoint, sf::Vector2f &position, float speed, float amplitude, float amplitudeSpeed)
: Monster(entryPoint, position, "./Assets/Sprites/VenerMonster.png", HEALTH, speed, amplitude, amplitudeSpeed, MonsterTypes::MT_ANGRY_MONSTER)
{
}

VenerMonster::~VenerMonster()
{
}
