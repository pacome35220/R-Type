/**
 * @file      Resource.hpp
 * @brief     This class is used get and create the textures
 * @details   This class works like a factory, the textureFactory create the texture
 * @details   linked with the entityID and the textureFactory creates the texture with the path
 */

#pragma once

#include <map>
#include <SFML/Graphics/Texture.hpp>
#include "EntityID.hpp"

/**
 * @namespace Package to manage whole entities in the project
 */
namespace Manager {
    /**
     * @class File "Include/Manager/Resource.hpp"
    */
    class Resource {
    public:
        Resource() = default;
        ~Resource() = default;

    public:
        void
        feedTextureFactory(enum EntityID id, const std::string &texturePath);
        bool loadTexture(enum EntityID id);
        sf::Texture &getTexture(enum EntityID id);
        const std::string &getTexturePath(enum EntityID id);

    private:
        std::map<enum EntityID, sf::Texture> textureMap;
        std::map<enum EntityID, std::string> textureFactory;
    };
}; // namespace Manager
