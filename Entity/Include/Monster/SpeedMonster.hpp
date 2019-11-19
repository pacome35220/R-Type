/**
 * @file      SpeedMonster.hpp
 * @brief     Description
 */

#pragma once
#include "Monster.hpp"
/**
 * @class SpeedMonster "Include/SpeedMonster.hpp"
 */
class SpeedMonster : Monster
{
public:
    SpeedMonster(ACore &entryPoint, sf::Vector2f &position, float speed, float amplitude, float amplitudeSpeed);
    ~SpeedMonster();
private:

};
