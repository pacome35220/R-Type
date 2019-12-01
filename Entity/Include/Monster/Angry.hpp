/**
 * @file Angry.hpp
 */

#pragma once

#include "AMonster.hpp"

/**
 * @namespace Monster
 * @brief To get all types of monsters
 */
namespace Monster {
/**
 * @class Angry "Include/Monster/Angry.hpp"
 * @brief This is the angry Monster
 * @details He's really angry against your, care about it
 */
class Angry: public AMonster {
public:
    Angry(ACore &entryPoint, const sf::Vector2f &position, float scale);

    void onDeath() override;
};
} // namespace Monster
