/*
** EPITECH PROJECT, 2019
** for_norme
** File description:
** CollisionManager.hpp
*/

#pragma once

#include <list>
#include "Entity.hpp"

class CollisionManager
{
public:
    bool getCollision(const string &type1, const string &type2) const;
    void setCollision(const string &type1, const string &type2, const bool &status);
    void processCollision(list<EntityPtr> &entityList);

private:
    bool rectCollision(Entity &entity1, Entity &entity2);
    bool pixelCollision(Entity &entity1, Entity &entity2);

private:
    map<string, map<string, bool>> collisionMatrix;
};
