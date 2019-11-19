/**
 * @file      Angry.hpp
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
 * @class Angry "Include/Angry.hpp"
 */
    class Angry : AMonster
    {
    public:
        Angry(ACore &entryPoint, sf::Vector2f &position, float speed, float amplitude,
              float amplitudeSpeed);
        ~Angry() override;

    private:
    };
}