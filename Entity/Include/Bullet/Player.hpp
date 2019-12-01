/**
 * @file      Player.hpp
 */

#pragma once

#include "ABullet.hpp"

/**
 * @namespace Package to get all types of bullets
 */
namespace Bullet {
    /**
     * @class Player "Include/Bullet/Player.hpp"
     * @brief This is the player Bullet
     * @details The conventional bullet used by the player
     */
    class Player: public ABullet {
    public:
        Player(const sf::Vector2f &position, ACore &entryPoint,
               float _amplitude);
        ~Player() = default;

    public:
        void updateBullet() override;
        static AEntityPtr createPlayerFromPacket(ACore &core, sf::Packet
        packet);
    };
}
