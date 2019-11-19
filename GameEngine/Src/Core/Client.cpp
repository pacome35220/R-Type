/*
** EPITECH PROJECT, 2019
** for_norme
** File description:
** CoreClient.cpp
*/

#include <iostream>
#include "Core/Client.hpp"
#include "Parallax.hpp"

Core::Client::Client(const std::string &windowTitle)
    : ACore(),
      window(sf::VideoMode::getDesktopMode(), windowTitle, sf::Style::Default) {
    this->network = std::make_shared<Manager::Network>();
    this->action = std::make_shared<Manager::Action>();
    this->audio = std::make_shared<Manager::Audio>();

    this->feedEntity(std::make_shared<Parallax>(*this, sf::Vector2f(0, 0)));
}

void Core::Client::run() {
    sf::Clock clock;
    size_t currentTotal = clock.getElapsedTime().asMicroseconds();
    size_t lastTotal = clock.getElapsedTime().asMicroseconds();
    static sf::Mutex mutex;

    while (window.isOpen()) {
        mutex.lock();
        currentTotal = clock.getElapsedTime().asMicroseconds();
        if (currentTotal - lastTotal >= 1000000 / this->frameRate) {
            clock.restart();
            this->handleWindowEvent();
            this->updateEntities();
            this->procTopQueue();
            // call function to handle collision
            this->renderEntities();
            this->procDelectionQueue();
            this->action->flush();
            this->network->streamInput(this->action);
            bool tmp = this->canFeed;
            this->canFeed = true;
            this->network->readSocket(*this);
            this->canFeed = tmp;
            lastTotal = currentTotal;
        }
        mutex.unlock();
    }
}

void Core::Client::handleWindowEvent() {
    sf::Event event;

    while (this->window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            this->window.close();
        if (event.type == sf::Event::GainedFocus)
            this->action->setIsFocused(true);
        if (event.type == sf::Event::LostFocus)
            this->action->setIsFocused(false);
    }
    if (this->action->isKeyReleased(sf::Keyboard::Escape))
        this->window.close();
}

void Core::Client::renderEntities() {
    this->window.clear(sf::Color(0, 0, 0, 0));
    for (auto const &entity : this->entities)
        entity->render(this->window);
    this->window.display();
}

void Core::Client::procDelectionQueue() {
    for (const auto &entityToDelete : this->deletionQueue) {
        auto tmp = std::find(this->entities.begin(), this->entities.end(),
                             entityToDelete);
        if (tmp != this->entities.end())
            this->entities.erase(tmp);
    }
    this->deletionQueue = std::vector<AEntityPtr>();
}

const sf::RenderWindow &Core::Client::getRenderWindow() const {
    return this->window;
}
