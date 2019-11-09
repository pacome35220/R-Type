/*
** EPITECH PROJECT, 2019
** for_norme
** File description:
** CoreClient.cpp
*/

#include <iostream>
#include "Core/CoreClient.hpp"

CoreClient::CoreClient(const std::string &windowTitle)
    : ACore(),
      window(sf::VideoMode::getDesktopMode(), windowTitle, sf::Style::Default) {
    this->networkManager = std::make_shared<NetworkManager>();
    this->actionManager = std::make_shared<ActionManager>();
}

void CoreClient::run() {
    while (window.isOpen()) {
        this->handleWindowEvent();

        this->updateEntities();
        this->renderEntities();
        std::cout << "hey client !" << std::endl;
    }
}

void CoreClient::handleWindowEvent() {
    sf::Event event;

    while (this->window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            this->window.close();
        if (event.type == sf::Event::GainedFocus)
            this->actionManager->setIsFocused(true);
        if (event.type == sf::Event::LostFocus)
            this->actionManager->setIsFocused(false);
    }
    if (this->actionManager->isKeyReleased(sf::Keyboard::Escape))
        this->window.close();
}

void CoreClient::renderEntities() {
    this->window.clear(sf::Color(0, 0, 0, 0));
    for (auto const &entity : this->entities)
        entity->render();
    this->window.display();
}
