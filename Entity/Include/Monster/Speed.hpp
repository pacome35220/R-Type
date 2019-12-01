/**
 * @file      Speed.hpp
 */

#pragma once

#include "AMonster.hpp"

/**
 * @namespace Monster
 * @brief To get all types of monsters
 */
namespace Monster {
    /**
     * @class Speed "Include/Monster/Speed.hpp"
     * @brief This is the speed Monster
     * @details Care he's faster than Flash McQueen
     */
    class Speed: public AMonster {
    public:
        Speed(ACore &entryPoint, const sf::Vector2f &position, float scale);

    public:
        void updateMonster() override;
    };
}
