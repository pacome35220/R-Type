/**
 * @file      Player.hpp
 */

#pragma once

#include "AEntity.hpp"
#include "ACore.hpp"

/**
 * @class Player "Include/Player.hpp"
 * @brief This is the player AEntity
 */
class Player: public AEntity {
public:
    Player(ACore &core, sf::Vector2f pos, int _playerNbr);
    ~Player() = default;

public:
    static AEntityPtr createPlayerFromPacket(ACore &core, sf::Packet packet);
    sf::Packet buildMyAsAPacket(network::PacketType packetType) override;
    void onCollision(AEntityPtr entity) override;
    void update() override;
    void increaseStreamTimer() override;

private:
    void handleInput();

private:
    int level;
    int playerNbr;
};
