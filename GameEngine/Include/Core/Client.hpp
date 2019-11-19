/*
** EPITECH PROJECT, 2019
** for_norme
** File description:
** Client.hpp
*/

#pragma once

#include "ACore.hpp"

/**
 * @namespace Core package
 */
namespace Core {
    /**
 * @class Client "Include/Core/Client.hpp"
 */
    class Client : public ACore {
    public:
        Client(const std::string &windowTitle);
        void run() override;
        const sf::RenderWindow &getRenderWindow() const;
        void procDelectionQueue() override;

    private:
        void renderEntities();
        void handleWindowEvent();


    private:
        sf::RenderWindow window;
    };
}

