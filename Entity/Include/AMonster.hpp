/**
 * @file AMonster.hpp
 */

#pragma once

#include "ACore.hpp"

/**
 * @class AMonster "Include/AMonster.hpp"
 * @brief This is the abstract class of Monster.
 * @details It will be inherited by all types of bullets (Monster package)
 * @details It inherits from AEntity
 */
class AMonster : public AEntity {
public:
    /**
     * @brief Construct a new AMonster::AMonster object
     *
     * @param position initial position
     * @param entryPoint Core reference
     * @param type enum EntityID
     * @param speed speed on the x-axis
     * @param amplitude
     * @param amplitudeSpeed
     * @param scale is used to scale the sprite
     */
    AMonster(const sf::Vector2f &position, ACore &entryPoint,
             enum EntityID type, float speed, float amplitude,
             float amplitudeSpeed, float scale);

public:
    void update() override;

    /**
     * @brief onCollision is called in a collision between this and \p entity
     *
     * @param entity
     */
    void onCollision(AEntityPtr entity) override;

    sf::Packet buildMyAsAPacket(network::PacketType packetType) override;
    static AEntityPtr createMonsterFromPacket(ACore &core, sf::Packet packet);

protected:
    /**
     * @brief is called whe health < 0
     */
    virtual void onDeath();

protected:
    /**
     * @brief is used to compute y-axis move
     */
    float counter;
    /**
     * @brief is used to compute y-axis move
     */
    float originalY;
    /**
     * @brief speed on the x-axis
     */
    float speed;
    /**
     * @brief is used to compute y-axis move
     */
    float amplitude;
    float amplitudeSpeed;
    /**
     * @brief is used to scale the sprite
     */
    float scale;
};
