/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** AEntity.cpp
*/

#include "AEntity.hpp"
#include "ACore.hpp"
#include "Error.hpp"

AEntity::AEntity(const sf::Vector2f &_position, ACore &_entryPoint,
                 enum EntityID _type)
    : Id(), type(_type), entryPoint(_entryPoint), position(_position),
      packetNumber(0), health(100), streamTimer(0) {
    if (!this->entryPoint.getResource()->loadTexture(_type))
        throw Error(std::to_string(_type) + " doesn't exist", __FILE__, __func__, __LINE__);
    this->texture = this->entryPoint.getResource()->getTexture(_type);
    this->sprite.setTexture(this->texture);
    this->sprite.setOrigin(this->texture.getSize().x / 2,
                           this->texture.getSize().y / 2);
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
    sf::Packet packet;

    packet << packetType;
    if (packetType == network::PT_ENTITY_UPDATE)
        packet << (unsigned int)this->id;
    packet << this->type << (unsigned int)this->id
           << this->entryPoint.getResource()->getTexturePath(this->type)
           << this->position.x << this->position.y; //<< _physicType;
    if (packetType == network::PT_ENTITY_UPDATE) {
        packet << (unsigned int)this->packetNumber;
        this->packetNumber++;
    }
    return packet;
}

/**
 * Update this with the \_packet
 * @param _packet
 */
void AEntity::updateFromPacket(sf::Packet packet) {
    int id;
    std::string texturePath;
    float posX;
    float posY;
    unsigned int packetNbr;

    packet >> id;
    packet >> texturePath;
    packet >> posX;
    packet >> posY;
    packet >> packetNbr;

    this->position.x = posX;
    this->position.y = posY;
    this->packetNumber = packetNbr;
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
