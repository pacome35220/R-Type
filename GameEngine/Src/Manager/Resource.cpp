/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** Manager/Resource.cpp
*/

#include <iostream>
#include "Error.hpp"
#include "Manager/Resource.hpp"

/**
 * @brief feedTextureFactory associate an EntityID with his path
 */
void Manager::Resource::feedTextureFactory(enum EntityID id,
                                           const std::string &texturePath) {
    std::cout << "id: " << id << " " << texturePath << std::endl;
    this->textureFactory[id] = texturePath;
}

/**
 * @brief After associating an id and a path by a feedTextureFactory call,
 * loadTexture
 * loads the texture by the previously stored path.
 */
bool Manager::Resource::loadTexture(enum EntityID id) {
    std::cout << "Resource::loadTexture: id: " << id << std::endl;
    if (this->textureMap.find(id) != this->textureMap.end())
        return true;
    this->textureMap[id] = sf::Texture();
    return this->textureMap[id].loadFromFile(this->textureFactory[id]);
}

/**
 * @brief Get a ready-to-use texture from EntityID
 */
sf::Texture &Manager::Resource::getTexture(enum EntityID id) {
    return this->textureMap[id];
}

/**
 * @brief Get a texture's path from EntityID
 */
const std::string &Manager::Resource::getTexturePath(enum EntityID id) {
    return this->textureFactory[id];
}
