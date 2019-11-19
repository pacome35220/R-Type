/**
 * @file      VenerMonster.hpp
 * @brief     Description
 */

#pragma once
#include "Monster.hpp"
/**
 * @class VenerMonster "Include/VenerMonster.hpp"
 */
class VenerMonster : Monster
{
public:
    VenerMonster(ACore &entryPoint, sf::Vector2f &position, float speed, float amplitude, float amplitudeSpeed);
    ~VenerMonster();
private:
};
