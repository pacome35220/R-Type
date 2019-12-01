/**
 * @file      DeathStar.hpp
 */

#pragma once

#include "ABullet.hpp"

/**
 * @namespace Bullet To get all types of bullets
 */
namespace Bullet {
    /**
     * @class DeathStar "Include/Bullet/DeathStar.hpp"
     * @brief This is the deathStar Bullet
     * @details Care, it is more powerful than a superlaser
     */
    class DeathStar: public ABullet {
    public:
        DeathStar(const sf::Vector2f &position, ACore &entryPoint,
                  float amplitude = 1, int counter = 0);
        ~DeathStar() = default;

    public:
        void updateBullet() override;
        static AEntityPtr createDeathStarFromPacket(ACore &core, sf::Packet
        packet);
    };
}
