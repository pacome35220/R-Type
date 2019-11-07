/*
** EPITECH PROJECT, 2019
** for_norme
** File description:
** EntityFactory.cpp
*/

#include "EntityFactory.hpp"
#include "Error.hpp"

void EntityFactory::feedFactory(
    int entityID, const std::function<std::unique_ptr<AEntity>(
                      ACore &core, sf::Packet packet)> &constructor) {

    try {
        this->entityList[entityID] = constructor;
    } catch (const std::exception &e) {
        throw Error(e.what(), __FILE__, __func__, __LINE__);
    }
}

std::unique_ptr<AEntity> EntityFactory::buildEntity(int entityID, ACore &core,
                                                    sf::Packet packet) {
    try {
        return this->entityList[entityID](core, packet);
    } catch (const std::exception &e) {
        throw Error(e.what(), __FILE__, __func__, __LINE__);
    }
}
