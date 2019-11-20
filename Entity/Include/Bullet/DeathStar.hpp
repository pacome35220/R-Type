/**
 * @file      DeathStar.hpp
 * @brief     Description
 */

#pragma once

#include "ABullet.hpp"

/**
 * @namespace Package to get all types of bullets
 */
namespace Bullet {
/**
 * @class DeathStar "Include/DeathStar.hpp"
 */
class DeathStar : public ABullet {
public:
    DeathStar(const sf::Vector2f &position, ACore &entryPoint, float amplitude = 1,
              int counter = 0);
    ~DeathStar() = default;

    void updateBullet() override;
};

} // namespace Bullet
