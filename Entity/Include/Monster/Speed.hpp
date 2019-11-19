/**
 * @file      Speed.hpp
 * @brief     Description
 */

#pragma once

#include "AMonster.hpp"

/**
 * @namespace Package to get all types of monster
 */
namespace Monster {
/**
 * @class Speed "Include/Speed.hpp"
 */
class Speed : public AMonster {
public:
    Speed(ACore &entryPoint, const sf::Vector2f &position);
};
} // namespace Monster
