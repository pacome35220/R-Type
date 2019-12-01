/**
 * @file DeathStar.hpp
 */

#pragma once

#include "ABullet.hpp"

/**
 * @namespace Bullet
 * @brief To get all types of bullets
 */
namespace Bullet {
/**
 * @class DeathStar "Include/Bullet/DeathStar.hpp"
 * @brief This is the deathStar Bullet
 * @details Care, it is more powerful than a superlaser
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
