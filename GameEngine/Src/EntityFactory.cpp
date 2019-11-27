/*
** EPITECH PROJECT, 2019
** for_norme
** File description:
** EntityFactory.cpp
*/

#include <iostream>
#include "EntityFactory.hpp"
#include "Error.hpp"

/**
 * Add an entity to the factory
 * @param entityID
 * @param constructor
 */
void EntityFactory::addEntity(
    enum EntityID entityID,
    std::function<AEntityPtr(ACore &core, sf::Packet packet)> constructor) {
    try {
        this->entityList[entityID] = constructor;
    } catch (const std::exception &e) {
        throw Error(e.what(), __FILE__, __func__, __LINE__);
    }
}

/**
 * Call the constructor of the chosen entity and create it
 * @param entityID
 * @param core
 * @param packet
 * @return The entity built
 */
AEntityPtr EntityFactory::buildEntity(enum EntityID entityID, ACore &core,
                                      sf::Packet packet) {
    try {
        std::cout << "EntityFactory::buildEntity: entityID: " << entityID << std::endl;
        return this->entityList[entityID](core, packet);
    } catch (const std::exception &e) {
        throw Error(e.what(), __FILE__, __func__, __LINE__);
    }
}
