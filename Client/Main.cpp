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

/**
 * Entry point of the program
 * @param ip
 * @param port
 */
void runClient(const std::string &ip, unsigned short port) {
    CoreClient core("R-Type Client");
    // sf::Vector2f pos(0, 0);
    // sf::Packet packet;
    // auto parallax = new Parallax(pos);
    // parallax->setId(-1);
    // core.addEntity(parallax);
    std::cout << ip << "mdr" << port << std::endl;
    core.getNetwork()->setIpTarget(ip);
    core.getNetwork()->setPortTarget(port);
    // core.getAudioManager()->playBgm("./Assets/Audio/BackgroundMusic.ogg");
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
