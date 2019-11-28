/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** Monster.cpp
*/

#include <iostream>
#include "AMonster.hpp"
#include "Bullet/Monster.hpp"
#include "Core/Client.hpp"

AMonster::AMonster(const sf::Vector2f &position, ACore &entryPoint, enum EntityID type, float speed, float amplitude, float amplitudeSpeed, float scale)
    : AEntity(position, entryPoint, type), speed(speed), amplitude(amplitude), amplitudeSpeed(amplitudeSpeed), scale(scale) {
    // Todo
}

AEntityPtr AMonster::createMonsterFromPacket(ACore &core, sf::Packet packet) {
    sf::Vector2f pos;
    sf::Uint64 id;
    int entity;
    float speed;
    float amplitude;
    float amplitudeSpeed;
    float scale;

    packet >> id >> pos.x >> pos.y >> speed >> amplitude >> amplitudeSpeed >> scale >> entity;

    std::cout << "Player::createMonsterFromPacket " << std::endl <<
    "\t" << "id: " << id << std::endl <<
    "\t" << "pos.x: " << pos.x << std::endl <<
    "\t" << "pos.y: " << pos.y << std::endl <<
    "\t" << "speed: " << speed << std::endl <<
    "\t" << "amplitude: " << amplitude << std::endl <<
    "\t" << "amplitudeSpeed: " << amplitudeSpeed << std::endl <<
    "\t" << "scale: " << scale << std::endl <<
    "\t" << "entity: " << entity << std::endl;

    auto tmp = std::make_shared<AMonster>(pos, core, (enum EntityID)entity,
        speed, amplitude, amplitudeSpeed, scale);

    tmp->setId(id);
    return tmp;
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
        ((Core::Client &)this->entryPoint).getAudio()->playSound(
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

sf::Packet AMonster::buildMyAsAPacket(network::PacketType packetType) {
    sf::Packet packet = AEntity::buildMyAsAPacket(packetType);

    packet << this->speed;
    packet << this->amplitude;
    packet << this->amplitudeSpeed;
    packet << this->scale;
    packet << this->type;
    std::cout << "AMonster::buildMyAsAPacket" << std::endl <<
    "\t" << "this->speed: " << this->speed << std::endl <<
    "\t" << "this->amplitude: " << this->amplitude << std::endl <<
    "\t" << "this->amplitudeSpeed: " << this->amplitudeSpeed << std::endl <<
    "\t" << "this->scale: " << this->scale << std::endl <<
    "\t" << "this->type: " << this->type << std::endl;

    return packet;
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
