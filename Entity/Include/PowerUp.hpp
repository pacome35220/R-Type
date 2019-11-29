/**
 * @file      PowerUp.hpp
 * @brief     Description
 */

#pragma once

#include <ACore.hpp>

/**
 * @class PowerUp "Include/PowerUp.hpp"
 */
class PowerUp : public AEntity {
public:
    PowerUp(ACore &core, const sf::Vector2f &position);

public:
    void onCollision(AEntityPtr entity) override;
    void update() override;
};
