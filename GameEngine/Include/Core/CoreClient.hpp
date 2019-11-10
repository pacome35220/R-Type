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
    void addEntity(AEntityPtr entity);
    const sf::RenderWindow &getRenderWindow() const;

private:
    void renderEntities();
    void handleWindowEvent();
    void procDelectionQueue() override;

private:
    sf::RenderWindow window;
    // std::shared_ptr<sf::RenderWindow> window;
};
