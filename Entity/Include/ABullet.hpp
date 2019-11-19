/**
 * @file      ABullet.hpp
 * @brief     Abstract class of Bullet.
 * @details   It will be inherited by all types of bullets
 */

#pragma once

#include "AEntity.hpp"
#include "ACore.hpp"

/**
 * @class ABullet "Include/ABullet.hpp"
 */
class ABullet : public AEntity {
public:
    ABullet(const sf::Vector2f &position, ACore &entryPoint, enum EntityID type,
            float amplitude, float counter);

public:
    void update() override;
    virtual void updateBullet() = 0;
    void onCollision(AEntityPtr entity) override;

protected:
    float amplitude;
    float counter;
    float originalY;
};
