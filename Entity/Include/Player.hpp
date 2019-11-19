/**
 * @file      Player.hpp
 * @brief     Description
 */

#pragma once

#include "AEntity.hpp"

/**
 * @class Player "Include/Player.hpp"
 */
class Player : public AEntity {
public:
    Player(ACore &core, sf::Vector2f pos, int playerNbr);
    ~Player() = default;

    static AEntityPtr createPlayerFromPacket(ACore &core, sf::Packet packet);
    void onCollision(AEntity *entity) override;
    void update() override;
};
