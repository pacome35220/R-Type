/*
** EPITECH PROJECT, 2019
** for_norme
** File description:
** CollisionManager.cpp
*/

#include "CollisionManager.hpp"

bool CollisionManager::getCollision(const string &type1, const string &type2) const
{
    if (type1 < type2)
        return collisionMatrix.at(type1).at(type2);
    else
        return collisionMatrix.at(type2).at(type1);
}

void CollisionManager::setCollision(const string &type1, const string &type2, const bool &status)
{
    if (type1 < type2)
        collisionMatrix[type1][type2] = status;
    else
        collisionMatrix[type2][type1] = status;
}

void CollisionManager::processCollision(list<AEntityPtr> &entityList)
{
    // TODO
}

bool CollisionManager::rectCollision(AEntity &entity1, AEntity &entity2)
{
    // TODO
}

bool CollisionManager::pixelCollision(AEntity &entity1, AEntity &entity2)
{
    // TODO
}
