/**
 * @file      Dolley.hpp
 * @brief     Description
 */

#pragma once

#include "AMonster.hpp"

/**
 * @namespace Package to get all types of monster
 */
namespace Monster {
/**
 * @class Dolley "Include/Dolley.hpp"
 */
class Dolley : public AMonster {
public:
    Dolley(ACore &entryPoint, const sf::Vector2f &position);

    void onDeath() override;
};
} // namespace Monster
