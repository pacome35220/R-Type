/**
 * @file      Resource.hpp
*/

#pragma once

#include <map>
#include <SFML/Graphics/Texture.hpp>
#include "EntityID.hpp"

/**
 * @namespace Manager
 * @brief To manage whole entities
 */
namespace Manager {
    /**
     * @class Resource "Include/Manager/Resource.hpp"
     * @brief Resource manages the texture creation
     * @details Resource works like a factory, the textureFactory create
     * the texture linked with the entityID and the textureFactory creates the
     * texture with the path
    */
    class Resource {
    public:
        Resource() = default;
        ~Resource() = default;

    public:
        void feedTextureFactory(enum EntityID id, const std::string
                &texturePath);
        bool loadTexture(enum EntityID id);
        sf::Texture &getTexture(enum EntityID id);
        const std::string &getTexturePath(enum EntityID id);

    private:
        std::map<enum EntityID, sf::Texture> textureMap;
        std::map<enum EntityID, std::string> textureFactory;
    };
}; // namespace Manager
