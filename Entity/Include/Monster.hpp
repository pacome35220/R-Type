/**
 * @file      Monster.hpp
 * @brief     This is the parent class of all the monsters
 * @details   It inherits from AEntity
 */

#pragma once

//TODO good import
#include "../../GameEngine/Include/AEntity.hpp"

/**
 * @class Monster "Include/Monster.hpp"
 */
class Monster : public AEntity
{
public:
    Monster(ACore *entryPoint, sf::Vector2f &position, std::string texturePath, size_t health, float speed,
            float amplitude, float amplitudeSpeed);
    ~Monster();
    float getCounter() const;
    void setCounter(float counter);
    float getOriginalY() const;
    void setOriginalY(float originalY);

public:
    void updateMonster();
    void onCollision(AEntity *entity) override;
    sf::Packet decodeEntityPacket(network::PACKET_TYPE packetType);
    void updateEntityPacket(sf::Packet packet);

protected:
    float counter;
    float originalY;
    float speed;
    float scale;
    float amplitude;
    float amplitudeSpeed;
    bool hasPowerUp;
    size_t health;
};
