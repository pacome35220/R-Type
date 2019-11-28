/**
 * @file      MonsterBullet.hpp
 * @brief     Description
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
class Monster : public ABullet {
public:
    Monster(const sf::Vector2f &position, ACore &entryPoint, float amplitude,
            int count);
    ~Monster() = default;
    static AEntityPtr createMonsterFromPacket(ACore &core, sf::Packet packet);
    void updateBullet() override;
};
} // namespace Bullet
