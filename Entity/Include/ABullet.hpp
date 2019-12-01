/**
 * @file      ABullet.hpp
 */

#pragma once

#include "AEntity.hpp"
#include "ACore.hpp"

/**
 * @class ABullet "Include/ABullet.hpp"
 * @brief This is the abstract class of Bullet.
 * @details It will be inherited by all types of bullets (Bullet package)
 */
class ABullet: public AEntity {
public:
    ABullet(const sf::Vector2f &position, ACore &entryPoint, enum EntityID type,
            float amplitude = 1);

public:
    void update() override;
    virtual void updateBullet() = 0;
    void onCollision(AEntityPtr entity) override;
    void increaseStreamTimer() override;

protected:
    float amplitude;
};
