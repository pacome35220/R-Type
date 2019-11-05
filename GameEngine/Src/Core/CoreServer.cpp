/*
** EPITECH PROJECT, 2019
** for_norme
** File description:
** CoreServer.cpp
*/

#include "Core/CoreServer.hpp"

void CoreServer::addEntity(AEntityPtr entity)
{
    ACore::addEntity(move(entity));
    // TODO send to clients
}

void CoreServer::removeEntity(AEntityPtr entity)
{
    ACore::removeEntity(move(entity));
    // TODO send to clients
}

void CoreServer::run()
{
    // TOOD
}
