/*
** EPITECH PROJECT, 2019
** for_norme
** File description:
** ACore.hpp
*/

#pragma once

#include <map>
//#include <SFML/Graphics.hpp> // ?
#include "AEntity.hpp"

using namespace std;

class ACore
{
public:
    virtual ~ACore() = default;
    virtual void addEntity(AEntityPtr entity);
    virtual void removeEntity(AEntityPtr entity);
    virtual void run() = 0;

protected:
    map<size_t, AEntityPtr> entityMap;
};
