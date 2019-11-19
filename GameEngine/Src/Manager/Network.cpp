/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** Network.cpp
*/

#include <iostream>
#include <cstring>
#include "Error.hpp"
#include "Manager/Network.hpp"
#include "Player.hpp"

Manager::Network::Network() {
    this->socket.setBlocking(false);
}

void Manager::Network::setIpTarget(const std::string &ipTarget) {
    this->ipTarget = ipTarget;
}

void Manager::Network::setPortTarget(unsigned short portTarget) {
    this->portTarget = portTarget;
}

const std::vector<Client> &Manager::Network::getClients() const {
    return this->clients;
}

EntityFactory &Manager::Network::getEntityFactory() {
    return this->entityFactory;
}

/**
 * onPlayerJoin generate Player entity at the default position
 * and add it in the list
 * @param core
 * @param senderIp
 * @param senderPort
 */
void Manager::Network::onPlayerJoin(ACore &core, const sf::IpAddress &senderIp,
                                    unsigned short senderPort) {
    sf::Vector2f newClientPosition(-90, 0);
    std::size_t playerNbr = this->clients.size();

    core.feedEntity(
        std::make_shared<Player>(core, newClientPosition, playerNbr));
    this->addNewClient(senderIp, senderPort);
}

/**
 * addNewClient check if the player isn't already playing and put a
 * well-initialize Client in the list
 * @param ip
 * @param port
 */
void Manager::Network::addNewClient(const sf::IpAddress &ip,
                                    unsigned short port) {
    Client newClient;

    for (const auto &value : this->getClients())
        if (value.ip == ip && value.port == port)
            throw Error("Client from " + ip.toString() + " on port " +
                            std::to_string(port) + " is already playing",
                        __FILE__, __func__, __LINE__);
    newClient.ip = ip;
    newClient.port = port;
    for (size_t i = 0; i < sf::Keyboard::KeyCount; i++)
        newClient.keyMap[i] = 0;
    this->clients.push_back(newClient);
}

void Manager::Network::bindSocket(unsigned short port) {
    if (this->socket.bind(port) != sf::Socket::Done)
        throw Error("Bind fail", __FILE__, __func__, __LINE__);
    std::cout << "Network is listening to port " << port << std::endl;
}

void Manager::Network::sendPacket(sf::Packet packet, sf::IpAddress ip,
                                  unsigned short port) {
    this->socket.send(packet, ip, port);
}

void Manager::Network::readSocket(ACore &core) {
    // Receiver variable
    sf::Packet packet;
    sf::IpAddress sender;
    unsigned short senderPort;

    int opCode;
    int entityID;
    int id;

    this->resetClientsKeyMap();

    auto state = this->socket.receive(packet, sender, senderPort);
    if (state == sf::Socket::NotReady)
        return;
    while (state == sf::Socket::Done) {

        packet >> opCode;
        auto networkCode = static_cast<enum network::PacketType>(opCode);

        if (networkCode == network::PT_PLAYER_JOIN &&
            this->clients.size() < 4) {
            this->onPlayerJoin(core, sender, senderPort);
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
            packet >> entityID;
            this->entityFactory.buildEntity((enum EntityID)entityID, core,
                                            packet);
        }

        if (networkCode == network::PT_ENTITY_UPDATE) {
            packet >> id;
            packet >> entityID;

            // If you miss the CREATION event, recreate it

            AEntityPtr target = core.getEntityFromId(id);
            if (!target) {
                core.feedEntity(this->entityFactory.buildEntity(
                        (enum EntityID)entityID, core, packet));
            } else {
                target->updateFromPacket(packet);
            }
        }

        if (networkCode == network::PT_ENTITY_DESTRUCTION) {
            packet >> id;
            core.addToDeletionQueue((enum EntityID)id);
        }
        state = this->socket.receive(packet, sender, senderPort);
    }
}

void Manager::Network::streamInput(std::shared_ptr<Action> actionManager) {
    auto pressedKey = actionManager->getKeyPressed();

    for (const auto &keyCode : pressedKey) {
        sf::Packet packet;

        packet << network::PT_INPUT;
        packet << keyCode;
        this->sendPacket(packet, this->ipTarget, this->portTarget);
    }
}

void Manager::Network::resetClientsKeyMap() {
    for (auto &client : this->clients)
        std::memset(client.keyMap, 0, sizeof(client.keyMap));
}

bool Manager::Network::isClientKeyPressed(std::size_t clientId,
                                          sf::Keyboard::Key key) {
    if (clientId >= this->clients.size())
        return false;
    return this->clients[clientId].keyMap[key % sf::Keyboard::KeyCount] != 0;
}

void Manager::Network::execEntityAction(const AEntityPtr &entity,
                                        network::PacketType packetType) {
    sf::Packet packet = entity->buildMyPacket(packetType);

    for (auto &client : this->clients)
        this->socket.send(packet, client.ip, client.port);
}
