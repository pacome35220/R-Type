/**
 * @file      EntityFactory.hpp
 * @brief     This is class is a factory.
 * @brief     This factory creates all the entity registered in it.
 */

#pragma once

#include <functional>
#include <SFML/Network.hpp>
#include "AEntity.hpp"

/**
 * @class EntityFactory "Include/EntityFactory.hpp"
 */
class EntityFactory {
public:
    EntityFactory() = default;
    ~EntityFactory() = default;

    void addEntity(
        enum EntityList entityID,
        std::function<AEntityPtr(ACore &core, sf::Packet packet)> constructor);
    AEntityPtr buildEntity(enum EntityList entityID, ACore &core,
                           sf::Packet packet);

private:
    std::map<enum EntityList,
             std::function<AEntityPtr(ACore &core, sf::Packet packet)>>
        entityList;
};
