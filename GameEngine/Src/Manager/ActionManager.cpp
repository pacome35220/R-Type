/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** ActionManager.cpp
*/

#include "Manager/ActionManager.hpp"
/*
 *   Constructors // Destructor
 */
Manager::ActionManager::ActionManager()
    : isFocused(true), internalKeyMap(), currentState(), previousState() {
    mapKey(sf::Keyboard::Up);
    mapKey(sf::Keyboard::Left);
    mapKey(sf::Keyboard::Down);
    mapKey(sf::Keyboard::Right);
    mapKey(sf::Keyboard::W);
}
void Manager::ActionManager::mapKey(sf::Keyboard::Key key)
{
    this->previousState[key] = false;
    this->currentState[key] = false;
}

/*
 *   Setters
 */
void Manager::ActionManager::setIsFocused(bool state)
{
    this->isFocused = state;
}

/*
 *   Methods
 */
bool Manager::ActionManager::isKeyPressed(sf::Keyboard::Key key)
{
    if (!this->isKeyMapped(key))
        this->mapKey(key);
    return (!this->previousState[key] && this->currentState[key]);
}
bool Manager::ActionManager::isKeyReleased(sf::Keyboard::Key key)
{
    if (!this->isKeyMapped(key))
        this->mapKey(key);
    return (this->previousState[key] && !this->currentState[key]);
}
bool Manager::ActionManager::isKeyDown(sf::Keyboard::Key key)
{
    if (!this->isKeyMapped(key))
        this->mapKey(key);
    return this->currentState[key];
}
bool Manager::ActionManager::isKeyUp(sf::Keyboard::Key key)
{
    if (!this->isKeyMapped(key))
        this->mapKey(key);
    return !this->currentState[key];
}
bool Manager::ActionManager::isKeyMapped(sf::Keyboard::Key key)
{
    if (this->previousState.find(key) == this->previousState.end() ||
        this->currentState.find(key) == this->currentState.end())
        return false;
    return true;
}
std::vector<sf::Keyboard::Key> Manager::ActionManager::getKeyPressed()
{
    std::vector<sf::Keyboard::Key> pressedKey;

    for (const auto &key : this->currentState)
        if (this->isKeyPressed(key.first) || this->isKeyDown(key.first))
            pressedKey.push_back(key.first);
    return pressedKey;
}

/**
 * Flush all keys
 */
void Manager::ActionManager::flush()
{
    if (!this->isFocused)
        return;
    for (const auto &it : this->currentState) {
        this->previousState[it.first] = this->currentState[it.first];
        this->currentState[it.first] = sf::Keyboard::isKeyPressed(it.first);
        if (this->currentState[it.first])
            this->internalKeyMap[it.first] = 1;
    }
}
