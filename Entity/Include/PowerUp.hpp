/**
 * @file      PowerUp.hpp
 * @brief     Description
 */

#pragma once

#include <ACore.hpp>

/**
 * @class PowerUp "Include/PowerUp.hpp"
 */
class PowerUp : public AEntity
{
public:
    PowerUp(ACore &core, sf::Vector2f &position);
    ~PowerUp() override;

public:
    void onCollision(AEntityPtr entity) override;
    void update() override;

private:

};
