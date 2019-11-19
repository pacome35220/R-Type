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
class ABullet : AEntity
{
public:
    ABullet(ACore &entryPoint, enum EntityList type, sf::Vector2f &position, std::string texturePath);
    ~ABullet() override;

public:
    void update() override;
    virtual void increaseStreamTimer() = 0;
    virtual void updateBullet() = 0;

protected:

};
