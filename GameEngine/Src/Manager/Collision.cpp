/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** Collision.cpp
*/

#include <string>
#include "Manager/Collision.hpp"

/**
 * Check if a collision is possible between \type1 and \type2
 * @param type1
 * @param type2
 * @return True | False
 */
bool Manager::Collision::getCollision(EntityID entity1, EntityID entity2) const
{
    // Todo
    return this->collisionMap[entity1][entity2]
}
/**
 * Set a collision between \type1 and \type2
 * @param type1
 * @param type2
 * @return True | False
 */
void Manager::Collision::setCollision(EntityID entity1, EntityID entity2, const bool &status)
{
    this->collisionMap[entity1][entity2] = status
}
/**
 * Operate the collision with entities in the lust \entityList
 * @param type1
 * @param type2
 * @return True | False
 */
void Manager::Collision::processCollision(std::list<AEntityPtr> &entityList)
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
bool Manager::Collision::rectCollision(AEntity &entity1, AEntity &entity2)
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
bool Manager::Collision::pixelCollision(AEntity &entity1, AEntity &entity2)
{
    (void) entity1;
    (void) entity2;
    // TODO
    return false;
}
