/**
 * @file      Action.hpp
 */

#pragma once

#include <map>
#include <SFML/Window/Keyboard.hpp>
#include <vector>

/**
 * @namespace Manager
 * @brief To manage whole entities
 */
namespace Manager {
    /**
     * @class Action  "Include/Manager/Action.hpp"
     * @brief Action manages the input of user's keyboard.
    */
    class Action {
    public:
        Action();
        ~Action() = default;
        void setIsFocused(bool state);

    public:
        bool isKeyPressed(sf::Keyboard::Key key);
        void updateKeyPressed();
        std::vector<sf::Keyboard::Key> getKeyPressed();

    private:
        bool isKeyMapped(sf::Keyboard::Key key);
        void mapKey(sf::Keyboard::Key key);

    private:
        bool isFocused;
        std::map<sf::Keyboard::Key, bool> currentState;
    };
}
