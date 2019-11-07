/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** AEntity.cpp
*/

#include "AEntity.hpp"

AEntity::AEntity(sf::Vector2f _position, std::string _texturePath, ACore *_entryPoint)
{
    //TODO
}
// AEntity::~AEntity()
// {
//     // TODO
// }

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
sf::Packet AEntity::buildMyPacket(network::PACKET_TYPE _packetType)
{
    //TODO
    return sf::Packet();
}
/**
 * Update this with the \_packet
 * @param _packet
 */
void AEntity::updateFromPacket(sf::Packet packet)
{
    //TODO
}
/**
 * Display this
 */
void AEntity::render()
{
    //TODO
}
