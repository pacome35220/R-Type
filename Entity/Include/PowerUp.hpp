/**
 * @file      PowerUp.hpp
 */

#pragma once

#include <ACore.hpp>

/**
 * @class PowerUp "Include/PowerUp.hpp"
 * @brief This is the power up AEntity
 */
class PowerUp : public AEntity {
public:
    PowerUp(ACore &core, const sf::Vector2f &position);

public:
    void onCollision(AEntityPtr entity) override;
    void update() override;
};
