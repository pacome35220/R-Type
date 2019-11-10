/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** Monster.cpp
*/

#include "Monster.hpp"

Monster::Monster(ACore *entryPoint, sf::Vector2f &position, std::string texturePath, size_t health,
                 float speed, float amplitude, float amplitudeSpeed) : AEntity(position, texturePath,
                                                                               entryPoint, "Monster")
{
    //TODO
}
Monster::~Monster()
{
    //TODO
}
float Monster::getCounter() const
{
    return counter;
}
void Monster::setCounter(float _counter)
{
    counter = _counter;
}
float Monster::getOriginalY() const
{
    return originalY;
}
void Monster::setOriginalY(float _originalY)
{
    originalY = _originalY;
}
/**
 *  Check if the is alive
 */
void Monster::updateMonster()
{
    //TODO
}
/**
 * Check and process the collision between this and \entity
 * @param entity
 */
void Monster::onCollision(AEntity *entity)
{
    //TODO
}
/**
 * Create an \packet with this
 * @param packetType
 * @return the
 */
sf::Packet Monster::decodeEntityPacket(network::PACKET_TYPE packetType)
{
    //TODO
    return sf::Packet();
}
void Monster::updateEntityPacket(sf::Packet packet)
{
    //TODO
}
