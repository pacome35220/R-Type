/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** Player.cpp
*/

#include "Player.hpp"
#include "Bullet/Player.hpp"

Player::Player(ACore &core, sf::Vector2f pos, int _playerNbr)
    : AEntity(pos, core, (enum EntityID)(EI_PLAYER + _playerNbr % 4 + 1)),
      playerNbr(_playerNbr) {}

AEntityPtr Player::createPlayerFromPacket(ACore &core, sf::Packet packet) {
    int id;
    int playerNbr;
    sf::Vector2f pos;
    std::string textPath;

    packet >> id >> textPath >> pos.x >> pos.y >> playerNbr;

    AEntityPtr player = std::make_shared<Player>(core, pos, playerNbr);

    // player->id = id;
    return player;
}

void Player::onCollision(AEntityPtr entity) {
    switch (entity->getEntityType()) {
    case EI_MONSTER_BULLET:
        this->health--;
        this->entryPoint.addToDeletionQueue(entity);
        break;
    case EI_CLASSIC_MONSTER:
        this->health -= 10;
        this->entryPoint.addToDeletionQueue(entity);
        break;
    case EI_DEATH_STAR:
    case EI_ASTEROID:
        // you dead lol
        // mdr t un ouf toi
        this->health = -100000;
    case EI_POWER_UP:
        this->level++;
        this->entryPoint.addToDeletionQueue(entity);
    case EI_HEALTH_UP:
        this->health += 20;
        this->entryPoint.addToDeletionQueue(entity);
    default:
        break;
    }
}

/**
 * handleInput move the player depending on input.
 * When Space is pressed and depending on the level, the player is able to shot
 * bullet in multiple direction
 */
void Player::handleInput() {
    auto network = this->entryPoint.getNetwork();

    if (network->isClientKeyPressed(this->playerNbr, sf::Keyboard::Up))
        this->position.y -= 2;
    if (network->isClientKeyPressed(this->playerNbr, sf::Keyboard::Down))
        this->position.y += 2;
    if (network->isClientKeyPressed(this->playerNbr, sf::Keyboard::Right))
        this->position.x += 1;
    if (network->isClientKeyPressed(this->playerNbr, sf::Keyboard::Left))
        this->position.x -= 1;

    if (network->isClientKeyPressed(this->playerNbr, sf::Keyboard::Space)) {
        if (this->level == 0)
            this->entryPoint.feedEntity(std::make_shared<Bullet::Player>(
                this->position, this->entryPoint, 0));
        else if (this->level == 1)
            for (int i = -1; i <= 1; i++)
                this->entryPoint.feedEntity(std::make_shared<Bullet::Player>(
                    this->position, this->entryPoint, i));
        else {
            this->entryPoint.feedEntity(std::make_shared<Bullet::Player>(
                this->position, this->entryPoint, 0));
            for (int i = -2; i <= 2; i++)
                this->entryPoint.feedEntity(std::make_shared<Bullet::Player>(
                    this->position, this->entryPoint, i));
        }
    }
}

void Player::update() {
    this->handleInput();
    if (this->position.x < -100 + 6)
        this->position.x = -100 + 6;
    if (this->position.y < -100 + 9.5)
        this->position.y = -100 + 9.5f;
    if (this->position.x > 100 - 6)
        this->position.x = 100 - 6;
    if (this->position.y > 100 - 9.5)
        this->position.y = 100 - 9.5f;
    if (this->health < 0)
        this->entryPoint.addToDeletionQueue(this->getId());
}
