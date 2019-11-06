/**
 * @file      NetworkManager.hpp
 * @brief     This is handle all the network functions
 */

#pragma once

#include <vector>
#include <SFML/Network/UdpSocket.hpp>
#include "Client.hpp"
#include "EntityFactory.hpp"
#include "PacketType.hpp"

using namespace sf;

typedef unsigned short uint16;

/**
 * @class NetworkManager "Include/NetworkManager.hpp"
 */
class NetworkManager
{
public:
    NetworkManager();
    ~NetworkManager();
    void setIpTarget(const string &ipTarget);
    void setPortTarget(uint16 portTarget);
    const vector<Client> &getClients() const;

public:
    void bindSocket(uint16 port);
    void sendPacket(Packet, IpAddress ip, uint16 port);
    void readSocket(ACore &core);
    bool isClientKeyPressed(int clientId, Keyboard::Key key);
    void execEntityAction(AEntity *entity, network::PACKET_TYPE packetType);

private:
    std::vector<Client> clients;
    UdpSocket socket;
    std::string ipTarget;
    uint16 portTarget;
    EntityFactory entityFactory;
};
