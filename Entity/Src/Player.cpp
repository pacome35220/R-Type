/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** Player.cpp
*/

#include "Player.hpp"

Player::Player(ACore &core, sf::Vector2f pos, int playerNbr)
    : AEntity(pos,
              "./Assets/Sprites/Player" + std::to_string(playerNbr % 4 + 1) +
                  ".png",
              core, EL_PLAYER) {}

AEntityPtr Player::createPlayerFromPacket(ACore &core, sf::Packet packet) {
    int id;
    int playerNbr;
    sf::Vector2f pos;
    std::string textPath;

    packet >> id >> textPath >> pos.x >> pos.y >> playerNbr;

    AEntityPtr player = std::make_shared<Player>(core, pos, playerNbr);

    // player->id = id;
    return player;
}

void Player::onCollision(AEntityPtr entity) {}

void Player::update() {}
