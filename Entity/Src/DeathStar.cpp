/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** DeathStar.cpp
*/

#include <Monster/Dolley.hpp>
#include <Bullet/DeathStar.hpp>
#include <iostream>
#include "DeathStar.hpp"
#include "PowerUp.hpp"

DeathStar::DeathStar(const sf::Vector2f &position, ACore &entryPoint, int health, int counter): AEntity(
        position, entryPoint, EntityID::EI_DEATH_STAR) {
    this->health = health;
    this->counter = counter;
}

void DeathStar::update() {
    if (health < 0)
        onDeath();

    if (this->position.x < -130)
        restoreDeathStar();

    this->position.x -= 0.1;
    shot();
}

AEntityPtr DeathStar::createDeathStarFromPacket(ACore &core, sf::Packet packet)
{
    sf::Vector2f pos;
    int health;
    int counter;
    sf::Uint64 id;

    packet >> id >> pos.x >> pos.y >> health >> counter;

    std::cout << "DeathStar::createDeathStarFromPacket " << std::endl <<
    "\t" << "id: " << id << std::endl <<
    "\t" << "pos.x: " << pos.x << std::endl <<
    "\t" << "pos.y: " << pos.y << std::endl <<
    "\t" << "health: " << health << std::endl <<
    "\t" << "counter: " << counter << std::endl;

    auto tmp = std::make_shared<DeathStar>(pos, core, health, counter);

    tmp->setId(id);
    return tmp;
}

void DeathStar::onCollision(AEntityPtr entity) {
    if (entity->getEntityType() == EntityID::EI_DEATH_STAR) {
        health--;
        entryPoint.addToDeletionQueue(getId());
    }
}

sf::Packet DeathStar::buildMyAsAPacket(network::PacketType packetType) {
    //TODO
    return AEntity::buildMyAsAPacket(packetType);
}

void DeathStar::increaseStreamTimer() {
    streamTimer += 15;
}

void DeathStar::onDeath() {
    sf::Vector2f spawn(160, std::rand() % 100 - 50);

    entryPoint.addToDeletionQueue(getEntityType());
    entryPoint.feedEntity(std::make_shared<DeathStar>(spawn, entryPoint));
    entryPoint.feedEntity(std::make_shared<PowerUp>(entryPoint, position));
    entryPoint.feedEntity(std::make_shared<Monster::Dolley>(entryPoint, position));
}

void DeathStar::shot() {
    sf::Vector2f spawn(this->position);

    if (counter < 20) {
        spawn.x += std::rand() % 7 - 7;
        entryPoint.feedEntity(std::make_shared<Bullet::DeathStar>(spawn, entryPoint));
        entryPoint.feedEntity(std::make_shared<Bullet::DeathStar>(spawn, entryPoint, -1));
    }
    counter++;
    if (counter >= 40)
        counter = 0;
}

/**
 * @brief Replace the DeathStar on the screen and restore its HP
 */
void DeathStar::restoreDeathStar() {
    this->position.x = 130;
    this->health = 1600;
}
