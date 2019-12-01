/**
 * @file      DeathStar.hpp
 * @brief     DeathStar bullet
 */

#pragma once

#include "ABullet.hpp"

/**
 * @namespace Package to get all types of bullets
 */
namespace Bullet {
    /**
     * @class DeathStar "Include/Bullet/DeathStar.hpp"
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
} // namespace Bullet
