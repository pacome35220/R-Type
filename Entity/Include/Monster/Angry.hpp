/**
 * @file      Angry.hpp
 * @brief     Description
 */

#pragma once

#include "AMonster.hpp"

/**
 * @namespace Package to get all types of monster
 */
namespace Monster {
/**
 * @class Angry "Include/Angry.hpp"
 */
class Angry : public AMonster {
public:
    Angry(ACore &entryPoint, const sf::Vector2f &position);
};
} // namespace Monster
