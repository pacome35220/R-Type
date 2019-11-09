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
    void feedEntity(AEntityPtr entity);
    // void addEntity(AEntityPtr entity);
    // void removeEntity(AEntityPtr entity);
    void run();

private:
    void renderEntities() override;
    void procDelectionQueue() override;
    void onPlayerJoin(const sf::IpAddress &senderIP, unsigned short senderPort);
};
