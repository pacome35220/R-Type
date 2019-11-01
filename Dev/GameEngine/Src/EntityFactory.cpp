/*
** EPITECH PROJECT, 2019
** for_norme
** File description:
** EntityFactory.cpp
*/

#include "EntityFactory.hpp"
#include "Error.hpp"

void EntityFactory::addBuilder(const string &type, const Builder &builder)
{
    builderMap[type] = builder;
}

EntityPtr EntityFactory::build(const string &type) const
{
    auto it = builderMap.find(type);

    if (it == builderMap.end())
        throw ERROR("builder \"" + type + "\" does not exist");
    return (*it)();
}
