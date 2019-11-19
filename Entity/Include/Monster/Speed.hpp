/**
 * @file      Speed.hpp
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
 * @class Speed "Include/Speed.hpp"
 */
    class Speed : AMonster
    {
    public:
        Speed(ACore &entryPoint, sf::Vector2f &position, float speed, float amplitude,
              float amplitudeSpeed);
        ~Speed() override;
    private:

    };
}
