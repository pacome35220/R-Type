/**
 * @file      Collision.hpp
 * @brief     This class manages all the entity collisions
 */

#pragma once

#include <map>
#include <list>
#include <memory>
#include "ACore.hpp"
#include "EntityID.hpp"

/**
 * @namespace Package to manage whole entities in the project
 */
namespace Manager {
    /**
     * @class Collision "Include/Manager/Collision.hpp"
    */
    class Collision {
    public:
        Collision() = default;
        ~Collision() = default;

    public:
        void detectCollision(const std::vector<AEntityPtr> &entityList);

    private:
        void processCollision(std::list<AEntityPtr> &entityList1,
                              std::list<AEntityPtr> &entityList2);
        bool entityCollision(const AEntityPtr &entity1, const AEntityPtr
        &entity2);
    };
}
