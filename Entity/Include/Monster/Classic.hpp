/**
 * @file      Classic.hpp
 */

#pragma once

#include "AMonster.hpp"

/**
 * @namespace Monster To get all types of monsters
 */
namespace Monster {
    /**
     * @class Classic "Include/Monster/Classic.hpp"
     * @brief This is the classic Monster
     * @details Care about this monster, he's malicious
     */
    class Classic: public AMonster {
    public:
        Classic(ACore &entryPoint, const sf::Vector2f &position, float speed,
                float amplitude, float amplitudeSpeed, float scale);

    public:
        void updateMonster() override;
    };
}
