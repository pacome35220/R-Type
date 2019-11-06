/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** CollisionManager.cpp
*/

#include "CollisionManager.hpp"

CollisionManager::CollisionManager()
{
    // TODO
}
CollisionManager::~CollisionManager()
{
    // TODO
}
/**
 * Check if a collision is possible between \type1 and \type2
 * @param type1
 * @param type2
 * @return True | False
 */
bool CollisionManager::getCollision(const string &type1, const string &type2) const
{
    // Todo
    if (type1 < type2)
        return collisionMatrix.at(type1).at(type2);
    else
        return collisionMatrix.at(type2).at(type1);
}
/**
 * Set a collision between \type1 and \type2
 * @param type1
 * @param type2
 * @return True | False
 */
void CollisionManager::setCollision(const string &type1, const string &type2, const bool &status)
{
    // Todo
    if (type1 < type2)
        collisionMatrix[type1][type2] = status;
    else
        collisionMatrix[type2][type1] = status;
}
/**
 * Operate the collision with entities in the lust \entityList
 * @param type1
 * @param type2
 * @return True | False
 */
void CollisionManager::processCollision(list<AEntityPtr> &entityList)
{
    // TODO
}
/**
 * //TODO
 * @param entity1
 * @param entity2
 * @return
 */
bool CollisionManager::rectCollision(AEntity &entity1, AEntity &entity2)
{
    // TODO
}
/**
 * //TODO
 * @param entity1
 * @param entity2
 * @return
 */
bool CollisionManager::pixelCollision(AEntity &entity1, AEntity &entity2)
{
    // TODO
}
