/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** Server.cpp
*/

#include <SFML/Network.hpp>
#include <iostream>
#include "Server.hpp"
#include "Core/Server.hpp"
#include "Monster/Classic.hpp"
#include "Monster/Angry.hpp"
#include "Monster/Dolley.hpp"
#include "Monster/Dumb.hpp"
#include "Monster/Speed.hpp"
#include "../Common/Error.hpp"

/**
 * Server entry point.
 * This server is the lobby (like in Fornite) binded on \port
 * All game rooms will be bind from \port + x
 * @param port
 */
void Server::start(unsigned short port) {
    int idx = 0;
    sf::Packet packet;
    sf::UdpSocket socket;
    sf::IpAddress sender;
    unsigned short senderPort;
    std::vector<sf::Thread *> threads;

    if (socket.bind(port) != sf::Socket::Done)
        throw Error("Bind fail", __FILE__, __func__, __LINE__);
    while (true) {
        if (socket.receive(packet, sender, senderPort) == sf::Socket::Done) {
            if (idx % 4 == 0) {
                port++;
                auto *thread = new sf::Thread(Server::threadEntryPoint, port);
                threads.push_back(thread);
                thread->launch();
            }
            auto answer = sf::Packet();
            answer << network::PT_PORT_REDIRECTION << port;
            socket.send(answer, sender, senderPort);
            idx++;
        }
    }
}

/**
 * entityFeeder generate random enemies in the game.
 * Feel free to add new enemies at the begenning to increase level.
 * @param core
 */
void Server::entityFeeder(Core::Server &core) {
    sf::Vector2f pos(100, 0);
    auto monsterPos = sf::Vector2f(100, 0);

    for (size_t i = 0; i < 2; i++) {
        sf::Vector2f randomPos(100, (std::rand() % 200) - 100);
        float speed = (float)(std::rand() % 200) / 100;
        float amplitude = (float)(std::rand() % 1000) / 100;
        float amplitudeSpeed = (float)(std::rand() % 5) / 100;

        core.feedEntity(std::make_shared<Monster::Classic>(core, monsterPos, speed, amplitude, amplitudeSpeed, 4));
        core.feedEntity(std::make_shared<Monster::Dumb>(core, randomPos, 4));
        core.feedEntity(std::make_shared<Monster::Speed>(core, randomPos, 4));
        core.feedEntity(std::make_shared<Monster::Angry>(core, randomPos, 4));
    }

    //sf::Vector2f v(90, 0);
    //core.feedEntity(new BlackStar(v));
    //sf::Vector2f pos2(100, 0);
   // core.feedEntity(new Asteroid(pos2));
}

/**
 * threadEntryPoint is executed in a thread representing a room.
 * The room is a new server binded on \port
 * @param port
 */
void Server::threadEntryPoint(unsigned short port) {
    Core::Server core;

    core.getNetwork()->bindSocket(port);
    Server::entityFeeder(core);
    core.run();
}
