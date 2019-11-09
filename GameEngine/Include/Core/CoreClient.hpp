/*
** EPITECH PROJECT, 2019
** for_norme
** File description:
** CoreClient.hpp
*/

#pragma once

#include "ACore.hpp"

class CoreClient : public ACore {
public:
    CoreClient(const std::string &windowTitle);
    void run() override;

private:
    void renderEntities() override;
    void handleWindowEvent();
    void procDelectionQueue() override;

private:
    sf::RenderWindow window;
};
