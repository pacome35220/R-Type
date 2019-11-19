/**
 * @file      Resource.hpp
 * @brief     This class is used to get the texture and sounds
 * @details   This class is a singleton.
 */

#pragma once

#include <map>
#include <list>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Audio/Sound.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Audio/Music.hpp>

/**
 * @namespace
 */
namespace Manager
{
    /**
   * @class File "Include/Resource.hpp"
   */
    class Resource
    {
    public:
        Resource &getInstance();
        sf::Texture *getTexture(std::string &texturePath);


    private:
        Resource() = default;
        ~Resource() = default;
        Resource(const Resource &resource) = delete;
        Resource operator=(const Resource &resource) = delete;
        sf::Texture *createTexture(const std::string &texturePath);

    private:
        static Resource resourceInstance;
        std::map<std::string, sf::Texture *> textureMap;
    };
};