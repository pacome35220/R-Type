/*
** EPITECH PROJECT, 2019
** for_norme
** File description:
** EntityFactory.hpp
*/

#pragma once

#include <string> // ?
#include "Entity.hpp"

using namespace std;
using namespace sf;

#define Builder function<EntityPtr()>

class EntityFactory // template ?
{
public:
    void addBuilder(const string &type, const Builder &builder);
    EntityPtr build(const string &type) const;

private:
    map<string, Builder> builderMap;
};
