/**
 * @file      Dumb.hpp
 * @brief     Description
 */

#pragma once

#include "AMonster.hpp"

/**
 * @namespace Monster To get all types of monsters
 */
namespace Monster {
    /**
     * @class Dumb "Include/Monster/Dumb.hpp"
     * @brief This is the dumb Monster
     * @details We don't know how this monster is here, he's just insane
     */
    class Dumb: public AMonster {
    public:
        Dumb(ACore &entryPoint, const sf::Vector2f &position, float scale);

    public:
        void updateMonster() override;
    };
}
