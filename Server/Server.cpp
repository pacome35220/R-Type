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
#include "Asteroid.hpp"
#include "DeathStar.hpp"
#include "../Common/Error.hpp"

/**
 * Server entry point.
 * This server is the lobby (like in Fornite) binded on \p port
 * All game rooms will be bind on a new free port
 * @param port lobby port
 */
void Server::start(unsigned short port) {
    int idx = 0;
    sf::Packet packet;
    sf::UdpSocket socket;
    sf::IpAddress sender;
    unsigned short senderPort;
    std::vector<sf::Thread *> threads;
    std::shared_ptr<sf::UdpSocket> roomSocket;

    if (socket.bind(port) != sf::Socket::Done)
        throw Error("Bind fail", __FILE__, __func__, __LINE__);
    std::cout << "Lobby on port: " << port << std::endl;
    while (true) {
        if (socket.receive(packet, sender, senderPort) == sf::Socket::Done) {
            if (idx % 4 == 0) {
                roomSocket = std::make_shared<sf::UdpSocket>();
                if (roomSocket->bind(0) != sf::Socket::Done)
                    throw Error("Bind fail", __FILE__, __func__, __LINE__);

                auto *thread = new sf::Thread(Server::threadEntryPoint, roomSocket);
                threads.push_back(thread);
                thread->launch();
            }

            auto answer = sf::Packet();
            answer << network::PT_PORT_REDIRECTION << roomSocket->getLocalPort();
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
    auto monsterPos = sf::Vector2f(100, 0);

    core.feedEntity(std::make_shared<DeathStar>(sf::Vector2f(90, 0), core));
    core.feedEntity(std::make_shared<Asteroid>(sf::Vector2f(100, 0), core));

    sf::Vector2f randomPos(100, (std::rand() % 200) - 100);
    float speed = (float)(std::rand() % 200) / 100;
    float amplitude = (float)(std::rand() % 1000) / 100;
    float amplitudeSpeed = (float)(std::rand() % 5) / 100;

    core.feedEntity(std::make_shared<Monster::Classic>(core, monsterPos, speed, amplitude, amplitudeSpeed, 4));
    core.feedEntity(std::make_shared<Monster::Dumb>(core, randomPos, 4));
    core.feedEntity(std::make_shared<Monster::Speed>(core, randomPos, 4));
    core.feedEntity(std::make_shared<Monster::Angry>(core, randomPos, 4));
}

/**
 * threadEntryPoint is executed in a thread representing a room.
 * The room receive un parameter a binded \p socket
 * @param socket
 */
void Server::threadEntryPoint(std::shared_ptr<sf::UdpSocket> socket) {
    std::cout << "New room on port: " << socket->getLocalPort() << std::endl;

    try {
        Core::Server core;

        core.getNetwork()->setSocket(socket);
        Server::entityFeeder(core);
        core.run();
    }
    catch (const Error &error) {
        std::cout << error.what() << std::endl;
        exit(1);
    }
}
