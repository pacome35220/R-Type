/**
 * @file      EntityFactory.hpp
 */

#pragma once

#include <functional>
#include <SFML/Network.hpp>
#include "AEntity.hpp"

/**
 * @class EntityFactory "Include/EntityFactory.hpp"
 * @brief This is class is a factory.
 * @details This factory creates all the entity registered in it.
 */
class EntityFactory {
public:
    EntityFactory() = default;
    ~EntityFactory() = default;

public:
    void addEntity(
        enum EntityID entityID,
        std::function<AEntityPtr(ACore &core, sf::Packet packet)> constructor);
    AEntityPtr buildEntity(enum EntityID entityID, ACore &core,
                           sf::Packet packet);

private:
    std::map<enum EntityID,
             std::function<AEntityPtr(ACore &core, sf::Packet packet)>>
        entityList;
};
