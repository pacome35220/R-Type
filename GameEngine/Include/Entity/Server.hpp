/**
 * @file      Server.hpp
 * @brief     Description
 */

#pragma once

#include "AEntity.hpp"
#include "ACore.hpp"

/**
 * @namespace Package used to instanciate different entity
 * @details   Package created because an Entity created on the server
 * @details   doesn't have to get a texture, that's why we created this package
 */
namespace Entity
{
    /**
 * @class File "Include/Server.hpp"
 */
    class Server: public AEntity {
    public:
        Server(const sf::Vector2f &_position, ACore &_entryPoint, enum EntityID _type);
        ~Server() = default;

    public:

    private:

    };
}