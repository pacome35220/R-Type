/**
 * @file      DumbMonster.hpp
 * @brief     Description
 */

#pragma once
#include "Monster.hpp"
/**
 * @class DumbMonster "Include/DumbMonster.hpp"
 */
class DumbMonster : Monster
{
public:
    DumbMonster(ACore &entryPoint, sf::Vector2f &position, float speed, float amplitude, float amplitudeSpeed);
    ~DumbMonster();
private:

};
