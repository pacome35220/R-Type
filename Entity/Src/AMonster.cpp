/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** Monster.cpp
*/

#include "AMonster.hpp"
#include "Bullet/Monster.hpp"

AMonster::AMonster(const sf::Vector2f &position, ACore &entryPoint, enum EntityID type, float speed, float amplitude, float amplitudeSpeed, float scale)
    : AEntity(position, entryPoint, type), speed(speed), amplitude(amplitude), amplitudeSpeed(amplitudeSpeed), scale(scale) {
    // Todo
}

AMonster::~AMonster() {
    // TODO
}

float AMonster::getCounter() const {
    return counter;
}
void AMonster::setCounter(float _counter) {
    counter = _counter;
}

float AMonster::getOriginalY() const {
    return originalY;
}
void AMonster::setOriginalY(float originalY) {
    this->originalY = originalY;
}

/**
 *  Check if the is alive
 */
void AMonster::updateMonster() {
    this->counter += this->amplitudeSpeed;

    this->position.x -= this->speed;
    this->position.y = this->originalY; // + cos(this->counter) * 10 *
                                        // this->amplitude; maths lib

    if (std::rand() % 100 < 2) {
        this->entryPoint.feedEntity(std::make_shared<Bullet::Monster>(
            this->position, this->entryPoint, 1, 0));
        this->entryPoint.getAudio()->playSound(
            "./Assets/Audio/PlayerLaser.ogg");
    }
}

void AMonster::update()
{
	this->counter += this->amplitudeSpeed;

	this->position.x -= this->speed;
	this->position.y = this->originalY; //+ cos(this->counter) * 10 * this->amplitude;

	if (std::rand() % 1000 < 5) {
		auto bullet = std::make_shared<Bullet::Monster>(this->position, this->entryPoint, this->amplitude, this->counter);
		entryPoint.feedEntity(bullet);
	}
	if (this->position.x < -110 || this->position.x > 110 || this->position.y < -130 || this->position.y > 130) {
		this->position.x = 109;
		this->position.y = this->originalY;
	}
	this->updateMonster();
}

/**
 * Check and process the collision between this and \entity
 * @param entity
 */
void AMonster::onCollision(AEntityPtr entity) {
    if (entity->getEntityType() == EI_PLAYER_BULLET) {
       this->health--;
       this->entryPoint.addToDeletionQueue(entity);
    }
}

/**
 * Create an \packet with this
 * @param packetType
 * @return the
 */
sf::Packet AMonster::decodeEntityPacket(network::PacketType packetType) {
    sf::Packet packet;

    packet << packetType;
    if (packetType == network::PT_ENTITY_UPDATE)
        packet << (unsigned int)this->id;
    packet << this->monsterType << (unsigned int)this->id;
    packet << this->position.x << this->position.y << this->amplitude
           << this->speed << this->amplitudeSpeed << this->scale
           << this->originalY << this->counter;
    return packet;
}

void AMonster::updateEntityPacket(sf::Packet packet) {
    int id;
    float posX;
    float posY;

    packet >> id;
    packet >> posX;
    packet >> posY;
    this->position.x = posX;
    this->position.y = posY;
}
