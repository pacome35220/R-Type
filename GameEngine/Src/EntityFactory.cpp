/*
** EPITECH PROJECT, 2019
** for_norme
** File description:
** EntityFactory.cpp
*/

#include "EntityFactory.hpp"
#include "Error.hpp"

void EntityFactory::addBuilder(const string &type, const Builder &builder, const BuilderLoad &builderLoad)
{
    builderMap[type] = builder;
    builderLoadMap[type] = builderLoad;
}

/**
 * Calls the constructor of the \p type
 * @param type
 * @return The constructor of the type
 */
AEntityPtr EntityFactory::build(const string &type) const
{
    return getBuilder(builderMap, type)();
}

/**
 * Calls the constructor given in \p packet
 * @param type
 * @return The constructor of the type
 */
AEntityPtr EntityFactory::build(Packet &packet) const
{
    string type;

    if (!(packet >> type))
        throw ERROR("can not extract entity type of packet");
    return getBuilder(builderLoadMap, type)(packet);
}
/**
 * Get the constructor given in parameters
 * @tparam T
 * @param map
 * @param type
 * @return The constructor
 */
template<typename T>
const T &EntityFactory::getBuilder(const map<string, T> &map, const string &type) const
{
    auto it = map.find(type);

    if (it == map.end())
        throw ERROR("builder \"" + type + "\" does not exist");
    return it->second;
}
