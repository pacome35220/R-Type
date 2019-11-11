#include "Monster/ClassicMonster.hpp"

#define HEALTH 25

ClassicMonster::ClassicMonster(ACore *entryPoint, sf::Vector2f &position, float speed, float amplitude, float amplitudeSpeed)
: Monster(entryPoint, position, "./Assets/Sprites/ClassicMonster.png", HEALTH, speed, amplitude, amplitudeSpeed, monsterTypes::MT_CLASSIC_MONSTER)
{
}

// ClassicMonster::~ClassicMonster()
// {

// }
