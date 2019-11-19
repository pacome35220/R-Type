/**
 * @file      Resource.hpp
 * @brief     This class is used to get the texture and sounds
 * @details   This class is a singleton.
 */

#pragma once

#include <map>
#include <list>
#include <SFML/Graphics/Texture.hpp>

/**
 * @namespace
 */
namespace Manager {
/**
 * @class File "Include/Resource.hpp"
 */
class Resource {
public:
    Resource() = default;
    ~Resource() = default;

    sf::Texture *createTexture(const std::string &texturePath);

private:
    std::map<std::string, sf::Texture *> textureMap;
};
}; // namespace Manager
