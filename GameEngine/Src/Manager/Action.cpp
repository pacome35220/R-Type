/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** Manager/Action.cpp
*/

#include <iostream>
#include "Manager/Action.hpp"

Manager::Action::Action() : isFocused(true) {
    this->mapKey(sf::Keyboard::Up);
    this->mapKey(sf::Keyboard::Left);
    this->mapKey(sf::Keyboard::Down);
    this->mapKey(sf::Keyboard::Right);
    this->mapKey(sf::Keyboard::Space);
    this->mapKey(sf::Keyboard::Escape);
}

void Manager::Action::setIsFocused(bool state) {
    this->isFocused = state;
}

bool Manager::Action::isKeyPressed(sf::Keyboard::Key key) {
    if (!this->isKeyMapped(key))
        this->mapKey(key);
    return this->currentState[key];
}

std::vector<sf::Keyboard::Key> Manager::Action::getKeyPressed() {
    std::vector<sf::Keyboard::Key> pressedKey;

    for (const auto &key : this->currentState)
        if (this->isKeyPressed(key.first))
            pressedKey.push_back(key.first);
    return pressedKey;
}

/**
 * @brief Flush all keys
 */
void Manager::Action::updateKeyPressed() {
    if (!this->isFocused)
        return;
    for (auto &it : this->currentState)
        it.second = sf::Keyboard::isKeyPressed(it.first);
}

void Manager::Action::mapKey(sf::Keyboard::Key key) {
    this->currentState[key] = false;
}

bool Manager::Action::isKeyMapped(sf::Keyboard::Key key) {
    return this->currentState.find(key) != this->currentState.end();
}
