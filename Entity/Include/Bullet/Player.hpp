/**
 * @file      Player.hpp
 * @brief     Description
 */

#pragma once

#include "ABullet.hpp"

/**
 * @namespace Package to get all types of bullets
 */
namespace Bullet {
/**
 * @class Player "Include/Player.hpp"
 */
class Player : public ABullet {
public:
    Player(const sf::Vector2f &position, ACore &entryPoint, float _amplitude);
    ~Player() = default;

    void updateBullet() override;
};
} // namespace Bullet
