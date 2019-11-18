/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** AEntity.cpp
*/

#include "AEntity.hpp"

AEntity::AEntity(sf::Vector2f _position, std::string _texturePath,
                 ACore *_entryPoint, enum EntityList _type)
    : Id(), type(_type), texturePath(_texturePath), entryPoint(_entryPoint),
      position(_position), packetNumber(0) {}

const sf::Vector2f &AEntity::getPosition() const {
    return position;
}

const sf::Sprite &AEntity::getSprite() const {
    return sprite;
}

void AEntity::setPosition(const sf::Vector2f &_position) {
    this->position = _position;
}

void AEntity::setSprite(const sf::Sprite &_sprite) {
    this->sprite = _sprite;
}

/**
 * Build a packet from this attributes
 * @param _packetType
 * @return The packet built
 */
sf::Packet AEntity::buildMyPacket(network::PacketType packetType) {
    sf::Packet packet;

    packet << packetType;
    if (packetType == network::PT_ENTITY_UPDATE)
        packet << (unsigned int)this->id;
    packet << this->type << (unsigned int)this->id << this->texturePath
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
 * Display this
 */
void AEntity::render(sf::RenderWindow &window) {
    this->sprite.setPosition(this->position);
    window.draw(this->sprite);
}
