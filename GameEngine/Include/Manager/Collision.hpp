/**
 * @file      Collision.hpp
 */

#pragma once

#include <map>
#include <list>
#include <memory>
#include "ACore.hpp"
#include "EntityID.hpp"

/**
 * @namespace Manager
 * @brief To manage whole entities
 */
namespace Manager {
    /**
     * @class Collision "Include/Manager/Collision.hpp"
     * @brief Collision manages the collision between entities
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
