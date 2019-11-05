/*
** EPITECH PROJECT, 2019
** for_norme
** File description:
** Entity.cpp
*/

#include "Entity.hpp"

Entity::Entity(ACore &_core, const string &_type)
    : core(_core), type(_type)
{
}

Entity::Entity(ACore &_core, const string &_type, Packet &packet)
    : Entity(_core, type)
{
    // TODO get id, position, sprite...
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

void Entity::update()
{
    // TODO ??
}

void Entity::onCollision(Entity &other)
{
    //
}

void aff(RenderTarget &renderTarget)
{
    // TODO ?
}
