/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** AEntity.cpp
*/

#include <iostream>
#include "AEntity.hpp"
#include "ACore.hpp"

AEntity::AEntity(const sf::Vector2f &_position, ACore &_entryPoint,
                 enum EntityID _type)
    : Id(), type(_type), entryPoint(_entryPoint), position(_position),
      health(100), streamTimer(0) {}

sf::Texture &AEntity::getTexture() {
    return texture;
}

sf::Sprite &AEntity::getSprite() {
    return sprite;
}

int AEntity::getStreamTimer() {
    return this->streamTimer;
}

enum EntityID AEntity::getEntityType() {
    return this->type;
}

void AEntity::increaseStreamTimer() {
    this->streamTimer++;
}

void AEntity::resetStreamTimer() {
    this->streamTimer = 0;
}

/**
 * Build a packet from this attributes
 * @param packetType
 * @return The packet built
 */
sf::Packet AEntity::buildMyAsAPacket(network::PacketType packetType) {
    sf::Packet packet;

    packet << packetType;
    packet << this->type;
    packet << (sf::Uint64)this->id;
    packet << this->position.x;
    packet << this->position.y;

    std::cout << "AEntity::buildMyAsAPacket " << std::endl << "\t"
              << "packetType: " << packetType << std::endl << "\t"
              << "this->type: " << this->type << std::endl << "\t"
              << "this->id: " << this->id << std::endl << "\t"
              << "this->position.x: " << this->position.x << std::endl << "\t"
              << "this->position.y: " << this->position.y << std::endl;

    return packet;
}

/**
 * Update this with the \p packet
 * @param packet
 */
void AEntity::updateFromPacket(sf::Packet packet) {
    sf::Uint64 id;

    packet >> id;
    packet >> this->position.x;
    packet >> this->position.y;

    std::cout << "AEntity::updateFromPacket" << std::endl << "\t"
              << "this->id: " << id << std::endl << "\t" << "this->position.x: "
              << this->position.x << std::endl << "\t" << "this->position.y: "
              << this->position.y << std::endl;
}

/**
 * @brief Display the window
 */
void AEntity::render(sf::RenderWindow &window) {
    this->sprite.setPosition(
            this->absoluteToRelativePosition(window.getSize()));
    window.draw(this->sprite);
}

/**
 * @brief Compute the correct coordinates according to the window
 * @param window
 */
sf::Vector2f AEntity::absoluteToRelativePosition(sf::Vector2u window) {
    sf::Vector2f vec;

    vec.x = (window.x / 2.0f)
            + (this->position.x / 100.0f) * (window.x - (window.x / 2.0f));
    vec.y = (window.y / 2.0f)
            + (this->position.y / 100.0f) * (window.y - (window.y / 2.0f));
    return vec;
}
