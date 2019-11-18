/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** Server.cpp
*/

#include <SFML/Network.hpp>
#include <iostream>
#include "Error.hpp"
#include "Server.hpp"
#include "Core/CoreServer.hpp"

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

void Server::entityFeeder(CoreServer &core) {
    sf::Vector2f pos(100, 0);
    auto monsterPos = sf::Vector2f(100, 0);

    for (size_t i = 0; i < 2; i++) {
        sf::Vector2f randomPos(100, (std::rand() % 200) - 100);
        float speed = (float)(std::rand() % 200) / 100;
        float amplitude = (float)(std::rand() % 1000) / 100;
        float amplitudeSpeed = (float)(std::rand() % 5) / 100;
        // auto monster = new ClassicMonster(monsterPos,
        //                                 speed,
        //                                 amplitude,
        //                                 amplitudeSpeed, 4);

        // auto dumbMonster = new DumbMonster(randomPos, 4);
        // auto speedMonster = new SpeedMonster(randomPos, 4);
        // auto venerMonster = new VenerMonster(randomPos, 4);
        // core.feedEntity(monster);
        // core.feedEntity(dumbMonster);
        // core.feedEntity(speedMonster);
        // core.feedEntity(venerMonster); // done
    }

    // sf::Vector2f v(90, 0);
    // core.feedEntity(new BlackStar(v));
    // sf::Vector2f pos2(100, 0);
    // core.feedEntity(new Asteroid(pos2));
}

void Server::threadEntryPoint(unsigned short port) {
    CoreServer core;

    core.getNetwork()->bindSocket(port);
    Server::entityFeeder(core);
    core.run();
}
