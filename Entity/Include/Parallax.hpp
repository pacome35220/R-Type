/**
 * @file      Parallax.hpp
 */

#pragma once

#include "AEntity.hpp"

/**
 * @class Parallax "Include/Parallax.hpp"
 * @brief This is the parallax AEntity
 * @details This is the background of the game
 */
class Parallax : public AEntity {
public:
    Parallax(ACore &core, sf::Vector2f pos);
    ~Parallax() = default;

public:
    static AEntityPtr createParallaxFromPacket(ACore &core, sf::Packet packet);
    void onCollision(AEntityPtr entity) override;
    void update() override;

private:
    sf::Clock clock;
    std::size_t lastTotal;
    std::size_t currentTotal;
};
