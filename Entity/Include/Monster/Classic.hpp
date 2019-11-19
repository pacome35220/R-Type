/**
 * @file      Classic.hpp
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
 * @class Classic "Include/Classic.hpp"
 */
    class Classic : public AMonster
    {
    public:
        Classic(ACore &entryPoint, sf::Vector2f &position, float speed, float amplitude,
                float amplitudeSpeed);
        ~Classic() override;

    private:

    };
}