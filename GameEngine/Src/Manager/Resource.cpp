/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** Resource.cpp
*/

#include "Manager/Resource.hpp"

Manager::Resource Manager::Resource::resourceInstance;

Manager::Resource &Manager::Resource::getInstance()
{
    return resourceInstance;
}

sf::Texture *Manager::Resource::getTexture(std::string &texturePath)
{
    return textureMap.find(texturePath) == textureMap.end() ? createTexture(texturePath)
                                                            : textureMap.find(texturePath)->second;
}

sf::Texture *Manager::Resource::createTexture(const std::string &texturePath)
{
    auto *newTexture = new sf::Texture();

    newTexture->loadFromFile(texturePath);
    this->textureMap[texturePath] = newTexture;
    return newTexture;
}

