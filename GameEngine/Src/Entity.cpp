/*
** EPITECH PROJECT, 2019
** for_norme
** File description:
** Entity.cpp
*/

#include <cmath>
#include "Entity.hpp"

Entity::Entity(ACore &_core, const string &_type)
    : core(_core), type(_type)
{
    // TODO sprite setOrigin
}

Entity::Entity(ACore &_core, const string &_type, Packet &packet)
    : Entity(_core, type)
{
    // TODO get id, position, sprite...
}

const string &Entity::getType() const
{
    return type;
}

const size_t &Entity::getHp() const
{
    return hp;
}

const Vector2f &Entity::getPosition() const
{
    return position;
}

const float &Entity::getAngle() const
{
    return angle;
}

void Entity::aff(RenderTarget &renderTarget)
{
    sprite.setPosition(position);
    sprite.setRotation(angle * 180.0 / M_PI);
    renderTarget.draw(sprite);
}
