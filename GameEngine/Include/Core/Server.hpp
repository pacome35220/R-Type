/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** Server.hpp
*/

#pragma once

#include "ACore.hpp"

/**
 * @namespace Core package
 */
namespace Core
{
    /**
 * @class Server "Include/Core/Server.hpp"
 */
    class Server : public ACore
    {
    public:
        Server();
        ~Server() = default;

    public:
        void run() override;
        void procDeletionQueue() override;
        void onPlayerJoin(const sf::IpAddress &senderIP, unsigned short senderPort);
        void feedEntity(AEntityPtr entity) override;
    };
}