/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** Collision.cpp
*/

#include <string>
#include "Manager/Collision.hpp"


bool Manager::Collision::entityCollision(const AEntityPtr &entity1, const AEntityPtr &entity2)
{
    sf::FloatRect colliderRect = entity1->getSprite().getGlobalBounds();
    sf::FloatRect otherRect = entity2->getSprite().getGlobalBounds();

    return colliderRect.contains(otherRect.left, otherRect.top) ||
           colliderRect.contains(otherRect.left + otherRect.width, otherRect.top) ||
           colliderRect.contains(otherRect.left, otherRect.top + otherRect.height) ||
           colliderRect.contains(otherRect.left + otherRect.width, otherRect.top + otherRect.height);
}

void Manager::Collision::processCollision(std::list<AEntityPtr> &entityList1, std::list<AEntityPtr> &entityList2)
{
    for (auto const &current: entityList1) {
        for (auto const &other: entityList2) {
            if (current->getId() == other->getId())
                continue;
            if (this->entityCollision(current, other) || this->entityCollision(other, current)) {
                current->onCollision(other);
                other->onCollision(current);
            }
        }
    }
}

void Manager::Collision::detectCollision(std::vector<AEntityPtr> &entityList)
{
    std::list<AEntityPtr> collider;
    // std::vector<ISprite *> lazy;

    for (auto &entity: entityList) {
        // if (sprites[i]->getPhysicType() == PT_LAZY)
        //     lazy.push_back(sprites[i]);
        // if (sprites[i]->getPhysicType() == PT_COLLIDER)
            collider.push_back(entity);
    }
    this->processCollision(collider, collider);
    // this->processCollision(core, collider, lazy);

}


// /**
//  * Check if a collision is possible between \type1 and \type2
//  * @param type1
//  * @param type2
//  * @return True | False
//  */
// bool Manager::Collision::getCollision(EntityID entity1, EntityID entity2) const
// {
//     return this->collisionMap.at(entity1).at(entity2);
// }
// /**
//  * Set a collision between \type1 and \type2
//  * @param type1
//  * @param type2
//  * @return True | False
//  */

// void Manager::Collision::setCollision(EntityID entity1, EntityID entity2, const bool &status)
// {
//     this->collisionMap[entity1][entity2] = status;
// }
// /**
//  * Operate the collision with entities in the lust \entityList
//  * @param type1
//  * @param type2
//  * @return True | False
//  */
// void Manager::Collision::processCollision(std::list<AEntityPtr> &entityList)
// {
//     (void) entityList;
//     // TODO
// }
// /**
//  * //TODO
//  * @param entity1
//  * @param entity2
//  * @return
//  */
// bool Manager::Collision::rectCollision(AEntity &entity1, AEntity &entity2)
// {
//     (void) entity1;
//     (void) entity2;
//     // TODO
//     return false;
// }
// /**
//  * //TODO
//  * @param entity1
//  * @param entity2
//  * @return
//  */
// bool Manager::Collision::pixelCollision(AEntity &entity1, AEntity &entity2)
// {
//     (void) entity1;
//     (void) entity2;
//     // TODO
//     return false;
// }
