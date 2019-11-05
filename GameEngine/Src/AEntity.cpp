/*
** EPITECH PROJECT, 2019
** for_norme
** File description:
** AEntity.cpp
*/

#include <cmath>
#include "AEntity.hpp"

AEntity::AEntity(ACore &_core, const string &_type)
    : core(_core), type(_type)
{
    // TODO sprite setOrigin
}

AEntity::AEntity(ACore &_core, const string &_type, Packet &packet)
    : AEntity(_core, type)
{
    // TODO get id, position, sprite...
}

const string &AEntity::getType() const
{
    return type;
}

const size_t &AEntity::getHp() const
{
    return hp;
}

const Vector2f &AEntity::getPosition() const
{
    return position;
}

const float &AEntity::getAngle() const
{
    return angle;
}

void AEntity::aff(RenderTarget &renderTarget)
{
    sprite.setPosition(position);
    sprite.setRotation(angle * 180.0 / M_PI);
    renderTarget.draw(sprite);
}
