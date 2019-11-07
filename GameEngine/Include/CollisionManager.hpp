/**
 * @file      CollisionManager.hpp
 * @brief     This class manages all the entity collisions
 */

#pragma once

#include <map>
#include <list>
#include <memory>

class AEntity;

#define AEntityPtr std::unique_ptr<AEntity>

/**
 * @class CollisionManager "Include/Collision.hpp"
 */
class CollisionManager
{
public:
    CollisionManager();
    ~CollisionManager();
    bool getCollision(const std::string &type1, const std::string &type2) const;
    void setCollision(const std::string &type1, const std::string &type2, const bool &status);

private:
    void processCollision(std::list<AEntityPtr > &entityList);
    bool rectCollision(AEntity &entity1, AEntity &entity2);
    bool pixelCollision(AEntity &entity1, AEntity &entity2);

private:
    std::map<std::string, std::map<std::string, bool>> collisionMatrix;
};
