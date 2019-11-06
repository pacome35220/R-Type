/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** AEntity.cpp
*/

#include "AEntity.hpp"

AEntity::AEntity(Vector2f &_position, std::string _texturePath, ACore *_entryPoint)
{
    //TODO
}
AEntity::~AEntity()
{
    // TODO
}

const Vector2f &AEntity::getPosition() const
{
    return position;
}
const Sprite &AEntity::getSprite() const
{
    return sprite;
}
const CollisionManager &AEntity::getCollisionManager() const
{
    return collisionManager;
}
void AEntity::setPosition(const Vector2f &_position)
{
    AEntity::position = _position;
}
void AEntity::setSprite(const Sprite &_sprite)
{
    AEntity::sprite = _sprite;
}
/**
 * Build a packet from this attributes
 * @param _packetType
 * @return The packet built
 */
Packet AEntity::buildMyPacket(network::PACKET_TYPE _packetType)
{
    //TODO
    return Packet();
}
/**
 * Update this with the \_packet
 * @param _packet
 */
void AEntity::updateFromPacket(Packet _packet)
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


