/*
** EPITECH PROJECT, 2019
** for_norme
** File description:
** CoreServer.hpp
*/

#pragma once

#include "ACore.hpp"

class CoreServer : public ACore {
public:
    CoreServer();
    ~CoreServer() = default;
    void run() override;
    void addEntity(AEntityPtr entity) override;

private:
    void renderEntities() override;
    void procDelectionQueue() override;
    void onPlayerJoin(const sf::IpAddress &senderIP, unsigned short senderPort);
};
