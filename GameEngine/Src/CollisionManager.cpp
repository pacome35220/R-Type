/*
** EPITECH PROJECT, 2019
** for_norme
** File description:
** CollisionManager.cpp
*/

#include <iostream> // ?
#include "CollisionManager.hpp"

bool CollisionManager::getCollision(const string &type1, const string &type2) const
{
    if (type1 < type2)
        return configMap.at(type1).at(type2);
    else
        return configMap.at(type2).at(type1);
}

void CollisionManager::setCollision(const string &type1, const string &type2, const bool &status)
{
    if (type1 < type2)
        configMap[type1][type2] = status;
    else
        configMap[type2][type1] = status;
}

void CollisionManager::processCollision(list<EntityPtr> &entityList)
{
    // TODO
}

bool CollisionManager::rectCollision(Entity &entity1, Entity &entity2)
{
    // TODO
}

bool CollisionManager::pixelCollision(Entity &entity1, Entity &entity2)
{
    // TODO
}
