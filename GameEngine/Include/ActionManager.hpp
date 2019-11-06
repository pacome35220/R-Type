/**
 * @file      ActionManager.hpp
 * @brief     This class manages the input of user's keyboard.
 */

#pragma once

/**
 * @class ActionManager ActionManager.hpp "Include/ActionManager.hpp"
 */
class ActionManager
{
public:

public:

private:
    bool isFocused;
    int internalKeyMap[sf::Keyboard::KeyCount];
    std::map<Key, bool> currentState;
    std::map<Key, bool> previousState;
};
