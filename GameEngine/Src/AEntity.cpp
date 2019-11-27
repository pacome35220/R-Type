/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** AEntity.cpp
*/

#include <iostream>
#include "AEntity.hpp"
#include "ACore.hpp"
#include "Error.hpp"

AEntity::AEntity(const sf::Vector2f &_position, ACore &_entryPoint,
                 enum EntityID _type)
    : Id(), type(_type), entryPoint(_entryPoint), position(_position),
      packetNumber(0), health(100), streamTimer(0) {}

sf::Texture &AEntity::getTexture() {
    return texture;
}

sf::Sprite &AEntity::getSprite() {
    return sprite;
}

void AEntity::increaseStreamTimer() {
    this->streamTimer++;
}

void AEntity::resetStreamTimer() {
    this->streamTimer = 0;
}

int AEntity::getStreamTimer() {
    return this->streamTimer;
}

enum EntityID AEntity::getEntityType() {
    return this->type;
}

/**
 * Build a packet from this attributes
 * @param _packetType
 * @return The packet built
 */
sf::Packet AEntity::buildMyAsAPacket(network::PacketType packetType) {
    std::cout << "AEntity::buildMyAsAPacket " << this->type << " " << this->id
              << std::endl;
    sf::Packet packet;

    packet << packetType;
    packet << this->type;
    packet << (sf::Uint64)this->id;
    packet << this->position.x;
    packet << this->position.y;

    std::cout << "AEntity::buildMyAsAPacket " << std::endl <<
    "\t" << "packetType: " << packetType << std::endl <<
    "\t" << "this->type: " << this->type << std::endl <<
    "\t" << "this->id: " << this->id << std::endl <<
    "\t" << "this->position.x: " << this->position.x << std::endl <<
    "\t" << "this->position.y: " << this->position.y << std::endl;

    return packet;
}

/**
 * Update this with the \_packet
 * @param _packet
 */
void AEntity::updateFromPacket(sf::Packet packet) {
    std::cout << "AEntity::updateFromPacket" << std::endl;

    sf::Vector2f pos;

    packet >> pos.x;
    packet >> pos.y;

    this->position = pos;
}

/**
 * Compute the correct coordinates according to the window
 * @param window
 */
sf::Vector2f AEntity::absoluteToRelativePosition(sf::Vector2u window) {
    sf::Vector2f vec;

    vec.x = (window.x / 2.0f) +
            (this->position.x / 100.0f) * (window.x - (window.x / 2.0f));
    vec.y = (window.y / 2.0f) +
            (this->position.y / 100.0f) * (window.y - (window.y / 2.0f));
    return vec;
}

/**
 * Display this
 */
void AEntity::render(sf::RenderWindow &window) {
    this->sprite.setPosition(
        this->absoluteToRelativePosition(window.getSize()));
    window.draw(this->sprite);
}
