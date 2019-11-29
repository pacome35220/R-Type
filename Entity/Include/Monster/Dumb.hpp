/**
 * @file      Dumb.hpp
 * @brief     Description
 */

#pragma once

#include "AMonster.hpp"

/**
 * @namespace Package to get all types of monster
 */
namespace Monster {
/**
 * @class Dumb "Include/Dumb.hpp"
 */
class Dumb : public AMonster {
public:
    Dumb(ACore &entryPoint, const sf::Vector2f &position, float scale);

    void updateMonster() override;
};
} // namespace Monster
