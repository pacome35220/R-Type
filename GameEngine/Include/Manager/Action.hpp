/**
 * @file      Action.hpp
 * @brief     This class manages the input of user's keyboard.
 */

#pragma once

#include <map>
#include <SFML/Window/Keyboard.hpp>
#include <vector>

/**
 * @namespace Package to manage whole entities in the project
 */
namespace Manager
{
    /**
     * @class Action  "Include/Action.hpp"
    */
    class Action
    {
    public:
        Action();
        ~Action() = default;
        void setIsFocused(bool state);

    public:
        bool isKeyPressed(sf::Keyboard::Key key);
        bool isKeyReleased(sf::Keyboard::Key key);
        bool isKeyDown(sf::Keyboard::Key key);
        bool isKeyUp(sf::Keyboard::Key key);
        bool isKeyMapped(sf::Keyboard::Key key);
        std::vector<sf::Keyboard::Key> getKeyPressed();
        void flush();

    private:
        void mapKey(sf::Keyboard::Key key);

    private:
        bool isFocused;
        int internalKeyMap[sf::Keyboard::KeyCount];
        std::map<sf::Keyboard::Key, bool> currentState;
        std::map<sf::Keyboard::Key, bool> previousState;
    };
}

