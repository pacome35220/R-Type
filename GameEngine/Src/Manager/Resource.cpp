/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** Resource.cpp
*/

#include "Manager/Resource.hpp"

bool Manager::Resource::addTexture(const std::string &texturePath) {
    this->textureMap[texturePath] = sf::Texture();
    return this->textureMap[texturePath].loadFromFile(texturePath);
}

sf::Texture &Manager::Resource::getTexture(const std::string &texturePath) {
    return this->textureMap[texturePath];
}
