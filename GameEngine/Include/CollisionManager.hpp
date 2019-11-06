/**
 * @file      CollisionManager.hpp
 * @brief     This class manages all the entity collisions
 */

#pragma once

#include <list>
#include "AEntity.hpp"

class CollisionManager
{
public:
    CollisionManager();
    ~CollisionManager();
    bool getCollision(const string &type1, const string &type2) const;
    void setCollision(const string &type1, const string &type2, const bool &status);
    void processCollision(list<AEntityPtr> &entityList);

private:
    bool rectCollision(AEntity &entity1, AEntity &entity2);
    bool pixelCollision(AEntity &entity1, AEntity &entity2);

private:
    map<string, map<string, bool>> collisionMatrix;
};
