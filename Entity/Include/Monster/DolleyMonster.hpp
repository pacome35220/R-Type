/**
 * @file      DolleyMonster.hpp
 * @brief     Description
 */

#pragma once
#include "Monster.hpp"
/**
 * @class DolleyMonster "Include/DolleyMonster.hpp"
 */
class DolleyMonster : Monster
{
public:
    DolleyMonster(ACore &entryPoint, sf::Vector2f &position, float speed, float amplitude, float amplitudeSpeed);
    ~DolleyMonster();
private:
};
