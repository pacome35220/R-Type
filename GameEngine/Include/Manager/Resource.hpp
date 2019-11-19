/**
 * @file      Resource.hpp
 * @brief     This class is used to get the texture and sounds
 * @details   This class is a singleton.
 */

#pragma once

#include <map>
#include <SFML/Graphics/Texture.hpp>
#include "EntityID.hpp"

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

    void feedTextureFactory(enum EntityID id, const std::string &texturePath);
    bool loadTexture(enum EntityID id);
    sf::Texture &getTexture(enum EntityID id);
    const std::string &getTexturePath(enum EntityID id);

private:
    std::map<enum EntityID, sf::Texture> textureMap;
    std::map<enum EntityID, std::string> textureFactory;
};
}; // namespace Manager
