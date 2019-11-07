/*
** EPITECH PROJECT, 2019
** for_norme
** File description:
** EntityFactory.cpp
*/

#include "EntityFactory.hpp"
#include "Error.hpp"

void EntityFactory::feedFactory(
    const std::string &type,
    const std::function<std::unique_ptr<AEntity>(
        ACore &core, sf::Packet packet)> &constructor) {

    try {
        this->entityList[type] = constructor;
    } catch (const std::exception &e) {
        throw Error(e.what(), __FILE__, __func__, __LINE__);
    }
}
