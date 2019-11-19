/**
 * @file      Dumb.hpp
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
 * @class Dumb "Include/Dumb.hpp"
 */
    class Dumb : AMonster
    {
    public:
        Dumb(ACore &entryPoint, sf::Vector2f &position, float speed, float amplitude,
             float amplitudeSpeed);
        ~Dumb() override;
    private:

    };
}