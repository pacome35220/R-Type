/**
 * @file      Player.hpp
 * @brief     Description
 */

#pragma once

#include "AEntity.hpp"
#include "ACore.hpp"

/**
 * @class Player "Include/Player.hpp"
 */
class Player : public AEntity {
public:
    Player(ACore &core, sf::Vector2f pos, int _playerNbr);
    ~Player() = default;

    static AEntityPtr createPlayerFromPacket(ACore &core, sf::Packet packet);
    void onCollision(AEntityPtr entity) override;
    void update() override;

private:
    void handleInput();

private:
    int level;
    int playerNbr;
};
