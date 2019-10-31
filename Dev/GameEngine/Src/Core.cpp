/*
** EPITECH PROJECT, 2019
** for_norme
** File description:
** Core.cpp
*/

#include "Core.hpp"

void Core::addEntity(EntityPtr &entity)
{
    entityMap[entity.getId()] = entity; // move ?
}

void Core::removeEntity(EntityPtr &entity)
{
    entityMap.erase(entity.getId());
}
