/**
 * @file      Client.hpp
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
 * @class File "Include/Client.hpp"
 */
    class Client: public AEntity {
    public:
        Client(const sf::Vector2f &position, ACore &entryPoint, enum EntityID type);
        ~Client() override = default;
    public:

    private:

    };
}

