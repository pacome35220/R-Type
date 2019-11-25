/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** Client.cpp
*/

#include "Error.hpp"
#include "Entity/Client.hpp"

Entity::Client::Client(const sf::Vector2f &_position, ACore &_entryPoint,
                 enum EntityID _type)
        : AEntity(_position, _entryPoint, _type) {
    if (!this->entryPoint.getResource()->loadTexture(_type))
        throw Error(std::to_string(_type) + " doesn't exist", __FILE__, __func__, __LINE__);
    this->texture = this->entryPoint.getResource()->getTexture(_type);
    this->sprite.setTexture(this->texture);
    this->sprite.setOrigin(this->texture.getSize().x / 2,
                           this->texture.getSize().y / 2);
}
