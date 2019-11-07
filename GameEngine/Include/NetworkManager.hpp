/**
 * @file      NetworkManager.hpp
 * @brief     This is handle all the network functions
 */

#pragma once

#include <vector>
#include <SFML/Network/UdpSocket.hpp>
#include "Core/ACore.hpp"
#include "Client.hpp"
#include "EntityFactory.hpp"
#include "PacketType.hpp"
#include "ActionManager.hpp"

/**
 * @class NetworkManager "Include/NetworkManager.hpp"
 */
class NetworkManager {
public:
    NetworkManager();
    ~NetworkManager() = default;
    void setIpTarget(const std::string &ipTarget);
    void setPortTarget(unsigned short portTarget);
    const std::vector<Client> &getClients() const;

public:
    void bindSocket(unsigned short port);
    void sendPacket(sf::Packet, sf::IpAddress ip, unsigned short port);
    void readSocket(ACore &core);
    void streamInput(ActionManager *actionManager);
    bool isClientKeyPressed(std::size_t clientId, Keyboard::Key key);
    void execEntityAction(const AEntityPtr &entity, network::PACKET_TYPE packetType);

private:
    void resetClientKeyMap();

private:
    std::vector<Client> clients;
    sf::UdpSocket socket;
    std::string ipTarget;
    unsigned short portTarget;
    EntityFactory entityFactory;
};
