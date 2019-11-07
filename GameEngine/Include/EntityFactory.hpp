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
    void feedFactory(const std::string &type,
                     const std::function<std::unique_ptr<AEntity>(
                         ACore &core, sf::Packet packet)> &constructor);

private:
    std::map<std::string, std::function<std::unique_ptr<AEntity>(
                              ACore &core, sf::Packet packet)>>
        entityList;
};
