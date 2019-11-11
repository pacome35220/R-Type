/*
** EPITECH PROJECT, 2019
** for_norme
** File description:
** CoreClient.cpp
*/

#include <iostream>
#include "Clock.hpp"
#include "Core/CoreClient.hpp"

CoreClient::CoreClient(const std::string &windowTitle)
    : ACore(),
      window(sf::VideoMode::getDesktopMode(), windowTitle, sf::Style::Default) {
    this->networkManager = std::make_shared<NetworkManager>();
    this->actionManager = std::make_shared<ActionManager>();
}

void CoreClient::run() {
    Clock clock;
    size_t currentTotal = clock.getTotalMicroseconds();
    size_t lastTotal = clock.getTotalMicroseconds();
    static sf::Mutex mutex;

    while (window.isOpen()) {
        mutex.lock();
        currentTotal = clock.getTotalMicroseconds();
        if (currentTotal - lastTotal >= 1000000 / this->frameRate) {
            clock.frame();
            this->handleWindowEvent();
            this->updateEntities();
            this->procTopQueue();
            // call function to handle collision
            this->renderEntities();
            this->procDelectionQueue();
            this->actionManager->flush();
            this->networkManager->streamInput(this->actionManager);
            bool tmp = this->canFeed;
            this->canFeed = true;
            this->networkManager->readSocket(*this);
            this->canFeed = tmp;
            lastTotal = currentTotal;
        }
        clock.tick();
        mutex.unlock();
    }
}

void CoreClient::addEntity(AEntityPtr entity) {
    if (this->canFeed)
        this->entities.push_back(entity);
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
        entity->render(this->window);
    this->window.display();
}

void CoreClient::procDelectionQueue() {
    for (const auto &entityToDelete : this->deletionQueue) {
        auto tmp = std::find(this->entities.begin(), this->entities.end(),
                             entityToDelete);
        if (tmp != this->entities.end())
            this->entities.erase(tmp);
    }
    this->deletionQueue = std::vector<AEntityPtr>();
}

const sf::RenderWindow &CoreClient::getRenderWindow() const {
    return this->window;
}
