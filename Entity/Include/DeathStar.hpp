/**
 * @file      Include/DeathStar.hpp
*/

#pragma once

#include "AEntity.hpp"
#include "ACore.hpp"

/**
 * @class DeathStar "Include/DeathStar.hpp"
 * @brief This is the deathStar AEntity
 * @details When this entity is killed, she dropped lots of monster and 1
 * power up
 */
class DeathStar : public AEntity {
public:
    DeathStar(const sf::Vector2f &position, ACore &entryPoint, int health = 1600, int counter = 0);
    ~DeathStar() = default;

public:
    void update() override;
    void onCollision(AEntityPtr entity) override;
    sf::Packet buildMyAsAPacket(network::PacketType packetType) override;
    void increaseStreamTimer() override;
    static AEntityPtr createDeathStarFromPacket(ACore &core, sf::Packet packet);

private:
    void onDeath();
    void shot();
    void restoreDeathStar();

private:
    int health;
    int counter;
};
