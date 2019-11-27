/**
 * @file      NetworkManager.hpp
 * @brief     This is handle all the network functions
 */

#pragma once

#include <vector>
#include <SFML/Network/UdpSocket.hpp>
#include "ACore.hpp"
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
 * @class Network "Include/Network.hpp"
 */
    class Network {
    public:
        Network();
        ~Network() = default;

        void setSocket(std::shared_ptr<sf::UdpSocket>);
        void setIpTarget(const std::string &ipTarget);
        void setPortTarget(unsigned short portTarget);
        const std::vector<Client> &getClients() const;
        EntityFactory &getEntityFactory();

    public:
        void onPlayerJoin(ACore &core, const sf::IpAddress &senderIp, unsigned short senderPort);
        void sendPacket(sf::Packet, sf::IpAddress ip, unsigned short port);
        void readSocket(ACore &core);
        void streamInput(std::shared_ptr<Action> action);
        bool isClientKeyPressed(std::size_t clientId, sf::Keyboard::Key key);
        void execEntityAction(AEntityPtr entity, network::PacketType packetType);
        void endOfStream();
    private:
        void addNewClient(const sf::IpAddress &ip, unsigned short port);
        void resetClientsKeyMap();

    private:
        std::vector<Client> clients;
        std::shared_ptr<sf::UdpSocket> socket;
        std::string ipTarget;
        unsigned short portTarget;
        EntityFactory entityFactory;
    };
} // namespace Manager
