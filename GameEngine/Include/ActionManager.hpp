/**
 * @file      ActionManager.hpp
 * @brief     This class manages the input of user's keyboard.
 */

#pragma once

#include <map>
#include <SFML/Window/Keyboard.hpp>
#include <vector>

using namespace sf;

/**
 * @class ActionManager ActionManager.hpp "Include/ActionManager.hpp"
 */
class ActionManager
{
public:
    ActionManager();
    virtual ~ActionManager();
    void setIsFocused(bool isFocused);

public:
    bool isKeyPressed(Keyboard::Key key);
    bool isKeyReleased(Keyboard::Key key);
    bool isKeyDown(Keyboard::Key key);
    bool isKeyUp(Keyboard::Key key);
    bool isKeyMapped(Keyboard::Key key);
    std::vector<Keyboard::Key> getKeyPressed();
    void flush();

private:
    bool isFocused;
    int internalKeyMap[Keyboard::KeyCount];
    std::map<Keyboard, bool> currentState;
    std::map<Keyboard::Key, bool> previousState;
};
