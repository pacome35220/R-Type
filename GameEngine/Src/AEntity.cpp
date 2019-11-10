/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** AEntity.cpp
*/

#include "AEntity.hpp"

AEntity::AEntity(sf::Vector2f _position, std::string _texturePath, ACore *_entryPoint, const std::string &_type)
    : position(_position), packetNumber(0), type(_type), texturePath(_texturePath), entryPoint( _entryPoint)
{
}

const sf::Vector2f &AEntity::getPosition() const
{
    return position;
}
const sf::Sprite &AEntity::getSprite() const
{
    return sprite;
}
const CollisionManager &AEntity::getCollisionManager() const
{
    return collisionManager;
}
void AEntity::setPosition(const sf::Vector2f &_position)
{
    AEntity::position = _position;
}
void AEntity::setSprite(const sf::Sprite &_sprite)
{
    AEntity::sprite = _sprite;
}
/**
 * Build a packet from this attributes
 * @param _packetType
 * @return The packet built
 */
sf::Packet AEntity::buildMyPacket(network::PACKET_TYPE packetType)
{
    sf::Packet packet;

	packet << packetType;
    if (packetType == network::PT_ENTITY_UPDATE)
        packet << (unsigned int) this->id;
	packet << this->type << (unsigned int) this->id << this->texturePath << this->position.x << this->position.y; //<< _physicType;
    if (packetType == network::PT_ENTITY_UPDATE) {
        packet << (unsigned int) this->packetNumber;
        this->packetNumber++;
    }
    return packet;
}
/**
 * Update this with the \_packet
 * @param _packet
 */
void AEntity::updateFromPacket(sf::Packet packet)
{
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

void AEntity::render(sf::RenderWindow *window)
{
    //sf::Vector2f spritePos = this->position;

	// spritePos.x = this->position.x; //this->entryPoint->absoluteToRelativeX(this->position.x);
	// spritePos.y = this->entryPoint->absoluteToRelativeY(this->position.y);
 	this->sprite.setPosition(this->position);
    if (window != nullptr)
        window->draw(this->sprite);
}
