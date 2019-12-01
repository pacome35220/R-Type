/**
 * @file      MonsterBullet.hpp
 * @brief     Monster bullet
 */

#pragma once

#include "ABullet.hpp"
/**
 * @namespace Package to get all types of bullets
 */
namespace Bullet {
    /**
     * @class Monster "Include/Monster.hpp"
     */
    class Monster: public ABullet {
    public:
        Monster(const sf::Vector2f &position, ACore &entryPoint,
                float amplitude, int count);
        ~Monster() = default;

    public:
        void updateBullet() override;
        static AEntityPtr createMonsterFromPacket(ACore &core, sf::Packet
        packet);
    };
} // namespace Bullet
