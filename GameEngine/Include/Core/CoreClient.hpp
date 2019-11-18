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
    const sf::RenderWindow &getRenderWindow() const;
    void procDelectionQueue() override;

private:
    void renderEntities();
    void handleWindowEvent();


private:
    sf::RenderWindow window;
};
