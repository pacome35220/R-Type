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
 * @class ActionManager  "Include/ActionManager.hpp"
 */
class ActionManager
{
public:
    ActionManager();
    virtual ~ActionManager();
    void setIsFocused(const bool &isFocused);

public:
    bool isKeyPressed(Keyboard::Key key);
    bool isKeyReleased(Keyboard::Key key);
    bool isKeyDown(Keyboard::Key key);
    bool isKeyUp(Keyboard::Key key);
    bool isKeyMapped(Keyboard::Key key);
    std::vector<Keyboard::Key> getKeyPressed();
    void flush();
private:
    void mapKey(sf::Keyboard::Key key);
private:
    bool isFocused;
    int internalKeyMap[Keyboard::KeyCount];
    std::map<sf::Keyboard::Key, bool> currentState;
    std::map<sf::Keyboard::Key, bool> previousState;
};
