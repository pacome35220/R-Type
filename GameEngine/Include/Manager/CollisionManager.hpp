/**
 * @file      CollisionManager.hpp
 * @brief     This class manages all the entity collisions
 */

#pragma once

#include <map>
#include <list>
#include <memory>
#include "EntityList.hpp"

class AEntity;

/**
 * @typedef Entity pointer to construct the entity
 */
typedef std::shared_ptr<AEntity> AEntityPtr;

/**
 * @namespace Package to manage whole entities in the project
 */
namespace Manager
{
/**
 * @class CollisionManager "Include/Collision.hpp"
 */
    class CollisionManager
    {
    public:
        CollisionManager() = default;
        ~CollisionManager() = default;
        bool getCollision(EntityList entity1, EntityList entity2) const;
        void setCollision(EntityList entity1, EntityList entity2, const bool &status);

    private:
        bool rectCollision(AEntity &entity1, AEntity &entity2);
        void processCollision(std::list<AEntityPtr> &entityList);
        bool pixelCollision(AEntity &entity1, AEntity &entity2);

    private:
        std::map<EntityList, std::map<EntityList, bool>> collisionMap;
    };
};
