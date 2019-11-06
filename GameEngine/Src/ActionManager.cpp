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
{
    // TODO
}
ActionManager::~ActionManager()
{
    // TODO
}
/*
 *   Getters // Setters
*/
void ActionManager::setIsFocused(bool isFocused)
{
    ActionManager::isFocused = isFocused;
}
/*
 *   Methods
*/
bool ActionManager::isKeyPressed(Keyboard::Key key)
{
    // TODO
    return false;
}
bool ActionManager::isKeyReleased(Keyboard::Key key)
{
    // TODO
    return false;
}
bool ActionManager::isKeyDown(Keyboard::Key key)
{
    // TODO
    return false;
}
bool ActionManager::isKeyUp(Keyboard::Key key)
{
    // TODO
    return false;
}
bool ActionManager::isKeyMapped(Keyboard::Key key)
{
    // TODO
    return false;
}
std::vector<Keyboard::Key> ActionManager::getKeyPressed()
{
    // TODO
    return std::vector<Keyboard::Key>();
}
/**
 * Flush all keys
 */
void ActionManager::flush()
{
    // TODO
}