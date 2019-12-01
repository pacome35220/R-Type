/**
 * @file      DeathStar.hpp
 * @brief     Description
 */

#pragma once

#include "ABullet.hpp"

/**
 * @namespace Package to get all types of bullets
 */
namespace Bullet {
/**
 * @class DeathStar "Include/DeathStar.hpp"
 */
class DeathStar : public ABullet {
public:
    DeathStar(const sf::Vector2f &position, ACore &entryPoint, float amplitude);
    ~DeathStar() = default;

    void updateBullet() override;

    sf::Packet buildMyAsAPacket(network::PacketType packetType) override;
    static AEntityPtr createDeathStarFromPacket(ACore &core, sf::Packet packet);
};

} // namespace Bullet
