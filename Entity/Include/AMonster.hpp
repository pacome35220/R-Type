/**
 * @file      Monster.hpp
 * @brief     This is the parent class of all the monsters
 * @details   It inherits from AEntity
 */

#pragma once

#include "ACore.hpp"
#include "MonsterID.hpp"

/**
 * @class Monster "Include/Monster.hpp"
 */
class AMonster : public AEntity {
public:
    AMonster(const sf::Vector2f &position,
             ACore &entryPoint, enum EntityID type);
    ~AMonster();
    float getCounter() const;
    void setCounter(float counter);
    float getOriginalY() const;
    void setOriginalY(float originalY);

public:
    void updateMonster();
    void onCollision(AEntityPtr entity);
    sf::Packet decodeEntityPacket(network::PacketType packetType);
    void updateEntityPacket(sf::Packet packet);

protected:
    float counter;
    float originalY;
    float speed;
    float scale;
    float amplitude;
    float amplitudeSpeed;
    bool hasPowerUp;
    enum MonsterID monsterType;
};
