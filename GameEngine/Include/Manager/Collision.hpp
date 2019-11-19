/**
 * @file      Collision.hpp
 * @brief     This class manages all the entity collisions
 */

#pragma once

#include <map>
#include <list>
#include <memory>
#include "EntityID.hpp"

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
 * @class Collision "Include/Collision.hpp"
 */
    class Collision
    {
    public:
        Collision() = default;
        ~Collision() = default;
        bool getCollision(EntityID entity1, EntityID entity2) const;
        void setCollision(EntityID entity1, EntityID entity2, const bool &status);

    private:
        bool rectCollision(AEntity &entity1, AEntity &entity2);
        void processCollision(std::list<AEntityPtr> &entityList);
        bool pixelCollision(AEntity &entity1, AEntity &entity2);

    private:
        std::map<EntityID, std::map<EntityID, bool>> collisionMap;
    };
}
