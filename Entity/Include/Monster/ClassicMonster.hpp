/**
 * @file      ClassicMonster.hpp
 * @brief     Description
 */

#pragma once
#include "Monster.hpp"

/**
 * @class ClassicMonster "Include/ClassicMonster.hpp"
 */
class ClassicMonster : Monster
{
public:
    ClassicMonster(ACore *entryPoint, sf::Vector2f &position, float speed, float amplitude, float amplitudeSpeed);
    ~ClassicMonster();
private:

};
