/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** Monster.cpp
*/

#include "Monster.hpp"

Monster::Monster(ACore *entryPoint, sf::Vector2f &position, std::string texturePath, size_t health, float speed, float amplitude, float amplitudeSpeed, monsterTypes monsterType) : AEntity(position, texturePath, entryPoint, "Monster"),
speed(speed), amplitude(amplitude), amplitudeSpeed(amplitudeSpeed), monsterType(monsterType), health(health)
{
    //Todo
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
    this->counter += this->amplitudeSpeed;

    this->position.x -= this->speed;
    this->position.y = this->originalY; // + cos(this->counter) * 10 * this->amplitude; maths lib

    if (std::rand() % 100 < 2) {
    	//auto bullet = new MonsterBullet(this->position);
    	//this->entryPoint.feedEntity(bullet);
    	//this->entryPoint.getAudioManager()->playSound("./Assets/Audio/PlayerLaser.ogg");
    }

}
/**
 * Check and process the collision between this and \entity
 * @param entity
 */
void Monster::onCollision(AEntity *entity)
{
    //if (sprite.getEntityType() == PLAYERBULLET_ID) {
	//    this->health--;
    //    this->entryPoint.addToDeletionQueue(sprite);
    //}
}
/**
 * Create an \packet with this
 * @param packetType
 * @return the
 */
sf::Packet Monster::decodeEntityPacket(network::PacketType packetType)
{
    sf::Packet packet;

    packet << packetType;
    if (packetType == network::PT_ENTITY_UPDATE)
        packet << (unsigned int) this->id;
    packet << this->monsterType << (unsigned int) this->id;
    packet << this->position.x << this->position.y << this->amplitude << this->speed << this->amplitudeSpeed << this->scale << this->originalY << this->counter;
    return packet;
}

void Monster::updateEntityPacket(sf::Packet packet)
{
    int id;
    float posX;
    float posY;

    packet >> id;
    packet >> posX;
    packet >> posY;
    this->position.x = posX;
    this->position.y = posY;
}
