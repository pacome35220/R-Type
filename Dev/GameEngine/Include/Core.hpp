/*
** EPITECH PROJECT, 2019
** for_norme
** File description:
** Core.hpp
*/

#pragma once

#include <map>
//#include <SFML/Graphics.hpp> // ?
#include "Entity.hpp"

using namespace std;

#define EntityPtr unique_ptr<Entity>

class Core
{
public:
    void addEntity(EntityPtr &entity);
    void removeEntity(EntityPtr &entity);

private:
    map<size_t, EntityPtr> entityMap;
};
