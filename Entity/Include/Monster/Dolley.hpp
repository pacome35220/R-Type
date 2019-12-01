/**
 * @file      Dolley.hpp
 */

#pragma once

#include "AMonster.hpp"

/**
 * @namespace Monster To get all types of monsters
 */
namespace Monster {
    /**
     * @class Dolley "Include/Monster/Dolley.hpp"
     * @brief This is the dolley Monster
     * @details Care, this is the most powerful monster you've ever seen
     */
    class Dolley: public AMonster {
    public:
        Dolley(ACore &entryPoint, const sf::Vector2f &position);

    public:
        void updateMonster() override;
    };
}
