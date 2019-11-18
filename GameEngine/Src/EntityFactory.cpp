/*
** EPITECH PROJECT, 2019
** for_norme
** File description:
** EntityFactory.cpp
*/

#include "EntityFactory.hpp"
#include "Error.hpp"

EntityFactory::EntityFactory() = default;
EntityFactory::~EntityFactory() = default;
/**
 * Add an entity to the factory
 * @param entityID
 * @param constructor
 */
void EntityFactory::addEntity(
    int entityID,
    const std::function<AEntityPtr(ACore &core, sf::Packet packet)>
        &constructor) {
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
AEntityPtr EntityFactory::buildEntity(int entityID, ACore &core, sf::Packet packet) {
    try {
        return this->entityList[entityID](core, packet);
    } catch (const std::exception &e) {
        throw Error(e.what(), __FILE__, __func__, __LINE__);
    }
}
