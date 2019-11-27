/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** main.cpp
*/

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Core/Client.hpp"
#include "Parallax.hpp"
#include "Player.hpp"
#include "../Common/Error.hpp"

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

    core.getResource()->feedTextureFactory(EI_PARALLAX, "./Assets/Sprites/starfieldBlue.png");
    core.getResource()->feedTextureFactory(EI_PLAYER1, "./Assets/Sprites/Player1.png");
    core.getResource()->feedTextureFactory(EI_PLAYER2, "./Assets/Sprites/Player2.png");
    core.getResource()->feedTextureFactory(EI_PLAYER3, "./Assets/Sprites/Player3.png");
    core.getResource()->feedTextureFactory(EI_PLAYER4, "./Assets/Sprites/Player4.png");

    core.getNetwork()->getEntityFactory().addEntity(EI_PLAYER1, Player::createPlayerFromPacket);
    core.getNetwork()->getEntityFactory().addEntity(EI_PLAYER2, Player::createPlayerFromPacket);
    core.getNetwork()->getEntityFactory().addEntity(EI_PLAYER3, Player::createPlayerFromPacket);
    core.getNetwork()->getEntityFactory().addEntity(EI_PLAYER4, Player::createPlayerFromPacket);

    core.getAudio()->playBackgroundMusic("./Assets/Audio/BackgroundMusic.ogg");

    core.getResource()->feedTextureFactory(EI_PARALLAX, "./Assets/Sprites/starfieldBlue.png");
    core.getResource()->feedTextureFactory(EI_PLAYER1, "./Assets/Sprites/Player1.png");
    core.getResource()->feedTextureFactory(EI_PLAYER2, "./Assets/Sprites/Player2.png");
    core.getResource()->feedTextureFactory(EI_PLAYER3, "./Assets/Sprites/Player3.png");
    core.getResource()->feedTextureFactory(EI_PLAYER4, "./Assets/Sprites/Player4.png");

    core.getNetwork()->getEntityFactory().addEntity(EI_PLAYER1, Player::createPlayerFromPacket);
    core.getNetwork()->getEntityFactory().addEntity(EI_PLAYER2, Player::createPlayerFromPacket);
    core.getNetwork()->getEntityFactory().addEntity(EI_PLAYER3, Player::createPlayerFromPacket);
    core.getNetwork()->getEntityFactory().addEntity(EI_PLAYER4, Player::createPlayerFromPacket);

    // core.getAudio()->playBackgroundMusic("./Assets/Audio/BackgroundMusic.ogg");

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
