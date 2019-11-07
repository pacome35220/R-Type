/*
** Server.cpp for Server in /Users/hadibereksi/Documents/Epitech/TEK3/CPP/CPP_rtype_2019/Server/Src
**
** Made by test
** Login   <hadi-ilies.bereksi-reguig>
**
** Started on  Wed Nov 6 10:57:12 AM 2019 test
** Last update Thu Nov 6 10:58:48 AM 2019 test
*/

#include <SFML/Network.hpp>
#include <iostream>
#include "Server.hpp"
#include "Core/CoreServer.hpp" 

void Server::start(unsigned short port)
{
    int idx = 0;
    sf::Packet packet;
    sf::UdpSocket socket;
    sf::IpAddress sender;
    unsigned short senderPort;
    std::vector<sf::Thread *> threads;

    if (socket.bind(port) != sf::Socket::Done)
        return;
    while (true) {
        auto state = socket.receive(packet, sender, senderPort);
        if (state == sf::Socket::Done) {
            if (idx % 4 == 0) {
                port++;
                auto *thread = new sf::Thread(Server::threadEntryPoint, port);
                threads.push_back(thread);
                thread->launch();
            }
            auto *answer = new sf::Packet();
            //*answer << network::PORT_REDIRECTION << port;
            socket.send(*answer, sender, senderPort);
            delete answer;
            idx++;
        }
    }
}

void Server::entityFeeder(CoreServer &core)
{
    sf::Vector2f pos(100, 0);
    auto monsterPos = sf::Vector2f(100, 0);
    for (int i = 0; i < 2; i++) {
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
        // core.feedEntity(venerMonster);
    }

// sf::Vector2f v(90, 0);
// core.feedEntity(new BlackStar(v));
// sf::Vector2f pos2(100, 0);
// core.feedEntity(new Asteroid(pos2));
}

void Server::threadEntryPoint(unsigned short port)
{
    CoreServer core;
    auto networkManager = core.getNetworkManager();

    // networkManager->setPlayerJoinCallback(Server::onPlayerJoin);
    networkManager->bindSocket(port);
    Server::entityFeeder(core);
    core.run();
}
void Server::onPlayerJoin(ACore &core, const sf::IpAddress &senderIP, const unsigned short &senderPort)
{
    // sf::Vector2f pos(-90, 0);
    //core.feedEntity(new Player(pos, (int)core.getNetworkManager()->getClientVector().size()));
    // for (const auto &value: core.getNetworkManager()->getClientVector())
    // 	if (value.ip == sender && value.port == senderPort)
    // 		return;
    // client_s client;

    // for (int i = 0; i < sf::Keyboard::KeyCount; i++)
    // 	client._keyMap[i] = 0;
    // client.ip = sender;
    // client.port = senderPort;
    // core.getNetworkManager()->getClientVector().push_back(client);
}
