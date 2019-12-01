/**
 * @file      MonsterBullet.hpp
 */

#pragma once

#include "ABullet.hpp"
/**
 * @namespace Bullet To get all types of bullets
 */
namespace Bullet {
    /**
     * @class Monster "Include/Bullet/Monster.hpp"
     * @brief This is the monster Bullet
     * @details The conventional bullet used by Monsters
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
}
