/*
** EPITECH PROJECT, 2019
** for_norme
** File description:
** ACore.cpp
*/

#include "ACore.hpp"

void ACore::addEntity(EntityPtr &entity)
{
    entityMap[entity.getId()] = entity; // move ?
}

void ACore::removeEntity(EntityPtr &entity)
{
    entityMap.erase(entity.getId());
}
