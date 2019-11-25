/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** Server.cpp
*/

#include "Entity/Server.hpp"

Entity::Server::Server(const sf::Vector2f &_position, ACore &_entryPoint,
                       enum EntityID _type)
        : AEntity(_position, _entryPoint, _type) {

}
