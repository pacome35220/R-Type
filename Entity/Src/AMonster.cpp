/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** Monster.cpp
*/

#include "AMonster.hpp"

AMonster::AMonster(ACore &entryPoint, sf::Vector2f &position, std::string texturePath, size_t health, float speed, float amplitude, float amplitudeSpeed, MonsterTypes monsterType) : AEntity(position, texturePath, entryPoint, EL_UNKNOWN),
                                                                                                                                                                                      speed(speed), amplitude(amplitude), amplitudeSpeed(amplitudeSpeed), monsterType(monsterType), health(health)
{
    //Todo
}

AMonster::~AMonster()
{
    //TODO
}

float AMonster::getCounter() const
{
    return counter;
}
void AMonster::setCounter(float _counter)
{
    counter = _counter;
}
float AMonster::getOriginalY() const
{
    return originalY;
}
void AMonster::setOriginalY(float _originalY)
{
    originalY = _originalY;
}

/**
 *  Check if the is alive
 */

void AMonster::updateMonster()
{
    this->counter += this->amplitudeSpeed;

    this->position.x -= this->speed;
    this->position.y = this->originalY; // + cos(this->counter) * 10 * this->amplitude; maths lib

    if (std::rand() % 100 < 2) {
    	this->entryPoint.feedEntity(new Bullet::Monster(this->position));
    	this->entryPoint.getAudio()->playSound("./Assets/Audio/PlayerLaser.ogg");
    }

}
/**
 * Check and process the collision between this and \entity
 * @param entity
 */
void AMonster::onCollision(AEntity *entity)
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
sf::Packet AMonster::decodeEntityPacket(network::PacketType packetType)
{
    sf::Packet packet;

    packet << packetType;
    if (packetType == network::PT_ENTITY_UPDATE)
        packet << (unsigned int) this->id;
    packet << this->monsterType << (unsigned int) this->id;
    packet << this->position.x << this->position.y << this->amplitude << this->speed << this->amplitudeSpeed << this->scale << this->originalY << this->counter;
    return packet;
}

void AMonster::updateEntityPacket(sf::Packet packet)
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
