/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** ActionManager.cpp
*/

#include "ActionManager.hpp"

/*
 *   Constructors // Destructor
*/
ActionManager::ActionManager()
    : isFocused(true), internalKeyMap(), previousState(), currentState()
{
    mapKey(sf::Keyboard::Up);
    mapKey(sf::Keyboard::Left);
    mapKey(sf::Keyboard::Down);
    mapKey(sf::Keyboard::Right);
    mapKey(sf::Keyboard::W);
}

ActionManager::~ActionManager()
{
    // TODO
}

void ActionManager::mapKey(sf::Keyboard::Key key)
{
    this->previousState[key] = false;
    this->currentState[key] = false;
}

/*
 *   Getters // Setters
*/
void ActionManager::setIsFocused(const bool &isFocused)
{
    this->isFocused = isFocused;
}

/*
 *   Methods
*/
bool ActionManager::isKeyPressed(Keyboard::Key key)
{
    if (!this->isKeyMapped(key))
	    this->mapKey(key);
	return (!this->previousState[key] && this->currentState[key]);
}

bool ActionManager::isKeyReleased(Keyboard::Key key)
{
    if (!this->isKeyMapped(key))
	    this->mapKey(key);
	return (this->previousState[key] && !this->currentState[key]);
}

bool ActionManager::isKeyDown(Keyboard::Key key)
{
    if (!this->isKeyMapped(key))
		this->mapKey(key);
	return this->currentState[key];
}

bool ActionManager::isKeyUp(Keyboard::Key key)
{
    if (!this->isKeyMapped(key))
		this->mapKey(key);
	return !this->currentState[key];
}

bool ActionManager::isKeyMapped(Keyboard::Key key)
{
    if (this->previousState.find(key) == this->previousState.end() || this->currentState.find(key) == this->currentState.end())
		return false;
	return true;
}

std::vector<Keyboard::Key> ActionManager::getKeyPressed()
{
    std::vector<sf::Keyboard::Key> pressedKey;

    for (auto it = this->currentState.begin(); it != this->currentState.end(); ++it)
        if (this->isKeyPressed(it->first) || this->isKeyDown(it->first))
            pressedKey.push_back(it->first);
    return pressedKey;
}

/**
 * Flush all keys
 */
void ActionManager::flush()
{
    if (!this->isFocused)
        return;
	for (auto it = this->currentState.begin(); it != this->currentState.end(); ++it) {
		this->previousState[it->first] = this->currentState[it->first];
		this->currentState[it->first] = sf::Keyboard::isKeyPressed(it->first);
		if (this->currentState[it->first])
			this->internalKeyMap[it->first] = 1;
	}
}
