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
    void addEntity(AEntityPtr entity);
    void removeEntity(AEntityPtr entity);

protected:
    map<size_t, AEntityPtr> entityMap;
};
