/*
** EPITECH PROJECT, 2019
** for_norme
** File description:
** Entity.cpp
*/

#include "Entity.hpp"

Entity::Entity(const string &_type)
    : type(_type)
{
}

Entity::Entity(const string &_type, Packet &packet)
    : Entity(type)
{
    // TODO get id, position, sprite...
}

void Entity::update()
{
    // TODO ??
}

void aff(RenderTarget &renderTarget)
{
    // TODO ?
}
