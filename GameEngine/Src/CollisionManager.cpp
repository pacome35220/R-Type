/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** CollisionManager.cpp
*/

#include <string>
#include "CollisionManager.hpp"

/**
 * Check if a collision is possible between \type1 and \type2
 * @param type1
 * @param type2
 * @return True | False
 */
bool CollisionManager::getCollision(EntityList entity1, EntityList entity2) const
{
    // Todo
}
/**
 * Set a collision between \type1 and \type2
 * @param type1
 * @param type2
 * @return True | False
 */
void CollisionManager::setCollision(EntityList entity1, EntityList entity2, const bool &status)
{
    // Todo
}
/**
 * Operate the collision with entities in the lust \entityList
 * @param type1
 * @param type2
 * @return True | False
 */
void CollisionManager::processCollision(std::list<AEntityPtr> &entityList)
{
    (void) entityList;
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
    (void) entity1;
    (void) entity2;
    // TODO
    return false;
}
/**
 * //TODO
 * @param entity1
 * @param entity2
 * @return
 */
bool CollisionManager::pixelCollision(AEntity &entity1, AEntity &entity2)
{
    (void) entity1;
    (void) entity2;
    // TODO
    return false;
}
