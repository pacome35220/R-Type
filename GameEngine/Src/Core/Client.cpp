/*
** EPITECH PROJECT, 2019
** for_norme
** File description:
** CoreClient.cpp
*/

#include <iostream>
#include "Core/Client.hpp"
#include "Error.hpp"
#include "Parallax.hpp"

Core::Client::Client(const std::string &windowTitle)
    : ACore(), window(sf::VideoMode::getDesktopMode(), windowTitle) {
    this->action = std::make_shared<Manager::Action>();
    this->audio = std::make_shared<Manager::Audio>();
    this->resource = std::make_shared<Manager::Resource>();
}

const sf::RenderWindow &Core::Client::getRenderWindow() const {
    return this->window;
}

std::shared_ptr<Manager::Audio> Core::Client::getAudio() const {
    return this->audio;
}

std::shared_ptr<Manager::Resource> Core::Client::getResource() const {
    return this->resource;
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
            this->procDeletionQueue();
            this->action->updateKeyPressed();
            this->network->streamInput(this->action);
            this->network->readSocket(*this);
            lastTotal = currentTotal;
        }
        mutex.unlock();
    }
}

/**
 * updateEntities call `update` method of each entities.
 */
void Core::Client::updateEntities() {
    for (std::size_t i = 0; i < this->entities.size(); i++)
        this->entities[i]->update();
}

void Core::Client::procDeletionQueue() {
    for (const auto &entityToDelete : this->deletionQueue) {
        auto tmp = std::find(this->entities.begin(), this->entities.end(),
                             entityToDelete);
        if (tmp != this->entities.end())
            this->entities.erase(tmp);
    }
    this->deletionQueue = std::vector<AEntityPtr>();
}

void Core::Client::feedEntity(AEntityPtr entity) {
    std::cout << "Client::feedEntity " << entity->getEntityType() << std::endl;

    this->entities.push_back(entity);
    if (!this->getResource()->loadTexture(entity->getEntityType()))
        throw Error(std::to_string(entity->getEntityType()) + " doesn't exist", __FILE__, __func__, __LINE__);
    entity->getTexture() = this->getResource()->getTexture(entity->getEntityType());
    entity->getSprite().setTexture(entity->getTexture());
    entity->getSprite().setOrigin(entity->getTexture().getSize().x / 2,
                           entity->getTexture().getSize().y / 2);
}

void Core::Client::renderEntities() {
    this->window.clear(sf::Color(0, 0, 0, 0));
    for (auto const &entity : this->entities)
        entity->render(this->window);
    this->window.display();
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
    if (this->action->isKeyPressed(sf::Keyboard::Escape))
        this->window.close();
}
