/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** DeathStar.cpp
*/


#include <Monster/Dolley.hpp>
#include <Bullet/DeathStar.hpp>
#include "DeathStar.hpp"
#include "PowerUp.hpp"

DeathStar::DeathStar(const sf::Vector2f &position, ACore &entryPoint, int health, int counter): AEntity(
        position, entryPoint, EntityID::EI_DEATH_STAR)
{
    this->health = health;
    this->counter = counter;
}

DeathStar::~DeathStar() = default;

void DeathStar::update()
{
    if(health < 0)
        death();

    if(this->position.x < -130)
        restoreDeathStar();

    this->position.x -= 0.1;
    fire();
}

void DeathStar::onCollision(AEntityPtr entity)
{
    if (entity->getEntityType() == EntityID::EI_DEATH_STAR) {
        health--;
        entryPoint.addToDeletionQueue(getId());
    }
}

sf::Packet DeathStar::buildMyPacket(network::PacketType packetType)
{
    return AEntity::buildMyPacket(packetType);
}

void DeathStar::increaseStreamTimer()
{
    streamTimer += 15;
}

void DeathStar::death()
{
    sf::Vector2f spawn(160, std::rand() % 100 - 50);

    entryPoint.addToDeletionQueue(getEntityType());
    entryPoint.feedEntity(std::make_shared<DeathStar>(spawn, entryPoint));
    entryPoint.feedEntity(std::make_shared<PowerUp>(entryPoint, position));
    entryPoint.feedEntity(std::make_shared<Monster::Dolley>(entryPoint, position));
}

void DeathStar::fire()
{
    sf::Vector2f spawn(this->position);

    if(counter < 20) {
        spawn.x += std::rand() % 7 - 7;
        entryPoint.feedEntity(std::make_shared<Bullet::DeathStar>(spawn, entryPoint));
        entryPoint.feedEntity(std::make_shared<Bullet::DeathStar>(spawn, entryPoint, -1));
    }
    counter++;
    if(counter >= 40)
        counter = 0;
}

/**
 * @brief Replace the DeathStar on the screen and restore its HP
 */
void DeathStar::restoreDeathStar()
{
    this->position.x = 130;
    this->health = 1600;
}
