/**
 * @file      Dolley.hpp
 * @brief     Description
 */

#pragma once
#include "AMonster.hpp"

/**
 * @namespace Package to get all types of monster
 */
namespace Monster
{
/**
 * @class Dolley "Include/Dolley.hpp"
 */
    class Dolley : AMonster
    {
    public:
        Dolley(ACore &entryPoint, sf::Vector2f &position, float speed, float amplitude,
               float amplitudeSpeed);
        ~Dolley() override;
    private:
    };
}