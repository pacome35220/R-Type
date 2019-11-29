/**
 * @file      Monster.hpp
 * @brief     This is the parent class of all the monsters
 * @details   It inherits from AEntity
 */

#pragma once

#include "ACore.hpp"

/**
 * @class Monster "Include/Monster.hpp"
 */
class AMonster : public AEntity {
public:
    AMonster(const sf::Vector2f &position, ACore &entryPoint, enum EntityID type, float speed, float amplitude, float amplitudeSpeed, float scale);

public:
    void update() override;
    static AEntityPtr createMonsterFromPacket(ACore &core, sf::Packet packet);
    virtual void updateMonster();
    void onCollision(AEntityPtr entity) override;
    sf::Packet buildMyAsAPacket(network::PacketType packetType) override;

protected:
    float counter;
    float originalY;
    float speed;
    float amplitude;
    float amplitudeSpeed;
    float scale;
};
