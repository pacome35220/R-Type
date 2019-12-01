/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** Monster.cpp
*/

#include <iostream>
#include <cmath>
#include "AMonster.hpp"
#include "Bullet/Monster.hpp"
#include "Core/Client.hpp"

AMonster::AMonster(const sf::Vector2f &position, ACore &entryPoint,
                   enum EntityID type, float _speed, float _amplitude,
                   float _amplitudeSpeed, float _scale)
    : AEntity(position, entryPoint, type) {
    this->originalY = position.y;
    this->scale = _scale;
    this->counter = 0;

    // this->speed = _speed;
    // this->amplitude = _amplitude;
    // this->amplitudeSpeed = _amplitudeSpeed;
    this->speed = (_speed < 0.1) ? 0.1 : (_speed > 1) ? 1 : _speed;
    this->amplitude = (_amplitude < 0.2) ? 0.2 : (_amplitude > 10) ? 10 : _amplitude;
    this->amplitudeSpeed = (_amplitudeSpeed < 0.01) ? 0.01 : (_amplitudeSpeed > 0.05) ? 0.05 : _amplitudeSpeed;

    this->getSprite().setScale(this->scale, this->scale);
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

    std::cout << "AMonster::createMonsterFromPacket " << std::endl <<
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

void AMonster::update()
{
	this->counter += this->amplitudeSpeed;

	this->position.x -= this->speed;
	this->position.y = this->originalY + std::cos(this->counter) * 10 * this->amplitude;

	if (std::rand() % 1000 < 5)
		entryPoint.feedEntity(std::make_shared<Bullet::Monster>(this->position, this->entryPoint));
	if (this->position.x < -110 || this->position.x > 110 || this->position.y < -130 || this->position.y > 130) {
		this->position.x = 109;
		this->position.y = this->originalY;
	}
	this->updateMonster();
}

void AMonster::updateMonster() {}

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
