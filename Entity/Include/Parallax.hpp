/**
 * @file      Parallax.hpp
 * @brief     Description
 */

#pragma once

#include "AEntity.hpp"

/**
 * @class Parallax "Include/Parallax.hpp"
 */
class Parallax : public AEntity {
public:
    Parallax(ACore &core, sf::Vector2f pos);
    ~Parallax() = default;

    static AEntityPtr createParallaxFromPacket(ACore &core, sf::Packet packet);
    void onCollision(AEntityPtr entity) override;
    void update() override;

private:
    sf::Clock clock;
    std::size_t lastTotal;
    std::size_t currentTotal;
};
