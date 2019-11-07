/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** NetworkManager.cpp
*/

#include <iostream>
#include <cstring>
#include "Error.hpp"
#include "NetworkManager.hpp"

NetworkManager::NetworkManager() {
    this->socket.setBlocking(false);
}

void NetworkManager::setIpTarget(const string &ipTarget) {
    this->ipTarget = ipTarget;
}

void NetworkManager::setPortTarget(unsigned short portTarget) {
    this->portTarget = portTarget;
}

const std::vector<Client> &NetworkManager::getClients() const {
    return this->clients;
}

void NetworkManager::bindSocket(unsigned short port) {
    if (this->socket.bind(port) != sf::Socket::Done)
        throw Error("Bind fail", __FILE__, __func__, __LINE__);
    std::cout << "NetworkManager is listening to port " << port << std::endl;
}

void NetworkManager::sendPacket(sf::Packet packet, sf::IpAddress ip,
                                unsigned short port) {
    this->socket.send(packet, ip, port);
}

void NetworkManager::readSocket(ACore &core) {
    // Receiver variable
    sf::Packet packet;
    sf::IpAddress sender;
    unsigned short senderPort;

    int opCode;
    int objectId;
    int id;

    this->resetClientKeyMap();

    auto state = this->socket.receive(packet, sender, senderPort);
    if (state == sf::Socket::NotReady)
        return;
    while (state == sf::Socket::Done) {

        packet >> opCode;
        auto networkCode = static_cast<enum network::PACKET_TYPE>(opCode);

        // A new player connected ?
        if (networkCode == network::PT_PLAYER_JOIN &&
            this->clients.size() < 4) {
            // if (_playerJoinCallback)
            // _playerJoinCallback(core, sender, senderPort);
            std::cout << "Someone joined with " << sender << ":" << senderPort
                      << std::endl;
        }

        if (networkCode == network::PT_PORT_REDIRECTION) {
            packet >> this->portTarget;
            sf::Packet answer;
            answer << network::PT_PLAYER_JOIN;
            this->sendPacket(answer, sender, this->portTarget);
        }

        if (networkCode == network::PT_ENTITY_CREATION) {
            packet >> objectId;
            // core.feedEntity(this->constructor[objectId](core, packet));
        }

        if (networkCode == network::PT_ENTITY_UPDATE) {
            packet >> id;
            packet >> objectId;

            // AEntity *target = core.getEntityFromId(id);
            // if (target == nullptr) {
            // 	core.feedEntity(_constructor[objectId](core, packet));
            // } else {
            //     target->updateFromPacket(packet);
            // }
        }

        if (networkCode == network::PT_ENTITY_DESTRUCTION) {
            packet >> id;
            // core.addToDeletionQueueById(id);
        }
        state = this->socket.receive(packet, sender, senderPort);
    }
}

void NetworkManager::resetClientKeyMap() {
    for (auto &client : this->clients)
        std::memset(client.keyMap, 0, sizeof(client.keyMap));
}

bool NetworkManager::isClientKeyPressed(std::size_t clientId,
                                        sf::Keyboard::Key key) {
    if (clientId >= this->clients.size())
        return false;
    return this->clients[clientId].keyMap[key % sf::Keyboard::KeyCount] != 0;
}

void NetworkManager::execEntityAction(AEntity *entity,
                                      network::PACKET_TYPE packetType) {
    // Todo
}
