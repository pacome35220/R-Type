/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** main.cpp
*/

#include <iostream>
#include <SFML/Graphics.hpp>

#include "Core/Client.hpp"
#include "Error.hpp"

#include "Asteroid.hpp"
#include "DeathStar.hpp"

#include "Monster/Classic.hpp"
#include "Monster/Dumb.hpp"
#include "Monster/Speed.hpp"
#include "Monster/Angry.hpp"
#include "Monster/Dolley.hpp"

#include "Bullet/DeathStar.hpp"
#include "Bullet/Monster.hpp"
#include "Bullet/Player.hpp"

#include "Parallax.hpp"

#include "Player.hpp"

/**
 * @brief Feed the factory with all the texture
 * @param core
 */
void feedTextureFactory(std::shared_ptr<Manager::Resource> resource) {
    resource->feedTextureFactory(EI_CLASSIC_MONSTER, "./Assets/Sprites/Monster/Classic.png");
    resource->feedTextureFactory(EI_DUMB_MONSTER, "./Assets/Sprites/Monster/Dumb.png");
    resource->feedTextureFactory(EI_SPEED_MONSTER, "./Assets/Sprites/Monster/Speed.png");
    resource->feedTextureFactory(EI_ANGRY_MONSTER, "./Assets/Sprites/Monster/Angry.png");
    resource->feedTextureFactory(EI_DOLLEY_MONSTER, "./Assets/Sprites/Monster/Dolley.png");

    resource->feedTextureFactory(EI_DEATH_STAR, "./Assets/Sprites/BlackStar.png");

    resource->feedTextureFactory(EI_ASTEROID1, "./Assets/Sprites/Asteroid1.png");
    resource->feedTextureFactory(EI_ASTEROID2, "./Assets/Sprites/Asteroid2.png");
    resource->feedTextureFactory(EI_ASTEROID3, "./Assets/Sprites/Asteroid3.png");
    resource->feedTextureFactory(EI_ASTEROID4, "./Assets/Sprites/Asteroid4.png");
    resource->feedTextureFactory(EI_ASTEROID5, "./Assets/Sprites/Asteroid5.png");
    resource->feedTextureFactory(EI_ASTEROID6, "./Assets/Sprites/Asteroid6.png");
    resource->feedTextureFactory(EI_ASTEROID7, "./Assets/Sprites/Asteroid7.png");

    resource->feedTextureFactory(EI_DEATH_STAR_BULLET, "./Assets/Sprites/BlackStarBullet.png");
    resource->feedTextureFactory(EI_MONSTER_BULLET, "./Assets/Sprites/MonsterBullet.png");
    resource->feedTextureFactory(EI_PLAYER_BULLET, "./Assets/Sprites/PlayerBullet.png");

    resource->feedTextureFactory(EI_PARALLAX, "./Assets/Sprites/starfieldBlue.png");

    resource->feedTextureFactory(EI_POWER_UP, "./Assets/Sprites/PowerUp.png");
    resource->feedTextureFactory(EI_HEALTH_UP, "./Assets/Sprites/HealthUp.png");

    resource->feedTextureFactory(EI_PLAYER1, "./Assets/Sprites/Player1.png");
    resource->feedTextureFactory(EI_PLAYER2, "./Assets/Sprites/Player2.png");
    resource->feedTextureFactory(EI_PLAYER3, "./Assets/Sprites/Player3.png");
    resource->feedTextureFactory(EI_PLAYER4, "./Assets/Sprites/Player4.png");
}

/**
 * @brief Feed EntityFactory
 * @param sharedPtr
 */
void feedEntityFactory(std::shared_ptr<Manager::Network> network) {
    // network->getEntityFactory().addEntity(EI_CLASSIC_MONSTER, AMonster::create);

    network->getEntityFactory().addEntity(EI_ASTEROID1, Asteroid::createAsteroidFromPacket);
    network->getEntityFactory().addEntity(EI_ASTEROID2, Asteroid::createAsteroidFromPacket);
    network->getEntityFactory().addEntity(EI_ASTEROID3, Asteroid::createAsteroidFromPacket);
    network->getEntityFactory().addEntity(EI_ASTEROID4, Asteroid::createAsteroidFromPacket);
    network->getEntityFactory().addEntity(EI_ASTEROID5, Asteroid::createAsteroidFromPacket);
    network->getEntityFactory().addEntity(EI_ASTEROID6, Asteroid::createAsteroidFromPacket);
    network->getEntityFactory().addEntity(EI_ASTEROID7, Asteroid::createAsteroidFromPacket);

    network->getEntityFactory().addEntity(EI_DEATH_STAR, DeathStar::createDeathStarFromPacket);

    network->getEntityFactory().addEntity(EI_PLAYER1, Player::createPlayerFromPacket);
    network->getEntityFactory().addEntity(EI_PLAYER2, Player::createPlayerFromPacket);
    network->getEntityFactory().addEntity(EI_PLAYER3, Player::createPlayerFromPacket);
    network->getEntityFactory().addEntity(EI_PLAYER4, Player::createPlayerFromPacket);
}

/**
 * Entry point of the program
 * @param ip
 * @param port
 */
void runClient(const std::string &ip, unsigned short port) {
    sf::Packet packet;
    Core::Client core("R-Type Client");

    std::cout << "Connecting to server on " << ip << ":" << port << std::endl;

    core.getNetwork()->setSocket(std::make_shared<sf::UdpSocket>());
    core.getNetwork()->setIpTarget(ip);
    core.getNetwork()->setPortTarget(port);

    feedTextureFactory(core.getResource());
    feedEntityFactory(core.getNetwork());

    core.getAudio()->playBackgroundMusic("./Assets/Audio/BackgroundMusic.ogg");

    core.feedEntity(std::make_shared<Parallax>(core, sf::Vector2f(0, 0)));
    packet << "Coucou Dolley"; // initialize connection with fake data : Server.cpp:25
    core.getNetwork()->sendPacket(packet, ip, port);

    core.run();
}

/**
 * Main client
 * @param argc
 * @param argv
 * @return
 */
int main(int argc, char **argv) {
    if (argc < 3)
        return EXIT_FAILURE;
    try {
        runClient(argv[1], std::stoi(argv[2]));
    } catch (const Error &error) {
        std::cerr << error.what() << std::endl;
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
