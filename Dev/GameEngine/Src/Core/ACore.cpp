/*
** EPITECH PROJECT, 2019
** for_norme
** File description:
** ACore.cpp
*/

#include "Core/ACore.hpp"

void ACore::addEntity(EntityPtr entity)
{
    entityMap[entity->getId()] = move(entity); // move ?
}

void ACore::removeEntity(EntityPtr entity)
{
    entityMap.erase(entity->getId());
}
