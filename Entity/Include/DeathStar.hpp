/**
 * @file      DeathStar.hpp
 * @brief     This is the big boss of the game
 * @details   When this entity is killed, she dropped lots of monster and one power up
 */

#pragma once

#include "AEntity.hpp"
#include "ACore.hpp"

/**
 * @class DeathStar "Include/DeathStar.hpp"
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
