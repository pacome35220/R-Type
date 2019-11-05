/*
** EPITECH PROJECT, 2019
** for_norme
** File description:
** ACore.cpp
*/

#include "Core/ACore.hpp"

void ACore::addEntity(AEntityPtr entity)
{
    entityMap[entity->getId()] = move(entity); // move ?
}

void ACore::removeEntity(AEntityPtr entity)
{
    entityMap.erase(entity->getId());
}
