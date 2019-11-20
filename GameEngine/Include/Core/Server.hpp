/*
** EPITECH PROJECT, 2019
** for_norme
** File description:
** Core.hpp
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
        void run() override;
        void procDeletionQueue() override;
        void onPlayerJoin(const sf::IpAddress &senderIP, unsigned short senderPort);
    };
}