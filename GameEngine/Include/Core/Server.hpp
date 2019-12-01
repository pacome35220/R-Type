/**
 * @file      Core/Client.hpp
 */

#pragma once

#include "ACore.hpp"

/**
 * @namespace Core
 * @brief To manage the entity on client or server side
 */
namespace Core {
    /**
     * @class Server "Include/Core/Server.hpp"
     * @brief This class manages all the server side ACore methods
    */
    class Server: public ACore {
    public:
        Server();
        ~Server() = default;

    public:
        void run() override;
        void updateEntities() override;
        void procDeletionQueue() override;
        void onPlayerJoin(const sf::IpAddress &senderIP, unsigned short
        senderPort);
        void feedEntity(AEntityPtr entity) override;
    };
}
