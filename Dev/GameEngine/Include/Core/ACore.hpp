/*
** EPITECH PROJECT, 2019
** for_norme
** File description:
** ACore.hpp
*/

#pragma once

#include <map>
//#include <SFML/Graphics.hpp> // ?
#include "Entity.hpp"

using namespace std;

#define EntityPtr unique_ptr<Entity> // move in Entity.hpp ?

class ACore
{
public:
    virtual ~ACore() = default;
    void addEntity(EntityPtr &entity);
    void removeEntity(EntityPtr &entity);

protected:
    map<size_t, EntityPtr> entityMap;
};
