/**
 * @file      Asteroid.hpp
 * @brief     Description
 */

#pragma once

#include <AEntity.hpp>
#include "ACore.hpp"

/**
 * @class Asteroid "Include/Asteroid.hpp"
 */
class Asteroid : public AEntity {
public:
    Asteroid(ACore &core, sf::Vector2f &position);
    ~Asteroid() = default;

public:
    static AEntityPtr createPlayerFromPacket(ACore &core, sf::Packet packet);
    void onCollision(AEntityPtr entity) override;
    void update() override;
    void increaseStreamTimer();

private:
    sf::Vector2f originalPos;
    sf::Vector2f target;
};
