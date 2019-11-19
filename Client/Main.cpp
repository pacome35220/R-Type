/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** main.cpp
*/

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Core/CoreClient.hpp"
#include "Error.hpp"
#include "Parallax.hpp"
#include "Player.hpp"

/**
 * Entry point of the program
 * @param ip
 * @param port
 */
void runClient(const std::string &ip, unsigned short port) {
    sf::Packet packet;
    CoreClient core("R-Type Client");

    std::cout << ip << "mdr" << port << std::endl;
    core.getNetwork()->setIpTarget(ip);
    core.getNetwork()->setPortTarget(port);
    core.getNetwork()->getEntityFactory().addEntity(EL_PLAYER, Player::createPlayerFromPacket);
    core.getAudio()->playBackgroundMusic("./Assets/Audio/BackgroundMusic.ogg");

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
