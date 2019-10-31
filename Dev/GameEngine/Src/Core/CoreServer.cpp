/*
** EPITECH PROJECT, 2019
** for_norme
** File description:
** CoreServer.cpp
*/

#include "CoreServer.hpp"

void CoreServer::addEntity(EntityPtr &entity)
{
    ACore::addEntity(entity);
    // TODO send to clients
}

void CoreServer::removeEntity(EntityPtr &entity)
{
    ACore::removeEntity(entity);
    // TODO send to clients
}
