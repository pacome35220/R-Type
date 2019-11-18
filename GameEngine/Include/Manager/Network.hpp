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
#include "Action.hpp"

/**
 * @namespace Package to manage whole entities in the project
 */
namespace Manager
{
    /**
     * @class NetworkManager "Include/NetworkManager.hpp"
    */
    class Network
    {
    public:
        Network();
        ~Network() = default;
        void setIpTarget(const std::string &ipTarget);
        void setPortTarget(unsigned short portTarget);
        const std::vector<Client> &getClients() const;
        void addNewClient(const sf::IpAddress &ip, unsigned short port);

    public:
        void bindSocket(unsigned short port);
        void sendPacket(sf::Packet, sf::IpAddress ip, unsigned short port);
        void readSocket(ACore &core);
        void streamInput(std::shared_ptr<Action> actionManager);
        bool isClientKeyPressed(std::size_t clientId, sf::Keyboard::Key key);
        void execEntityAction(const AEntityPtr &entity, network::PacketType packetType);
        EntityFactory getEntityFactory() const;

    private:
        void resetClientsKeyMap();

    private:
        std::vector<Client> clients;
        sf::UdpSocket socket;
        std::string ipTarget;
        unsigned short portTarget;
        EntityFactory entityFactory;
    };
};
