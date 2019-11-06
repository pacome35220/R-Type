/**
 * @file      EntityFactory.hpp
 * @brief     This is class is a factory.
 * @brief     This factory creates all the entity registered in it.
 */


#pragma once

#include <string> // ?
#include <functional>
#include <SFML/Network.hpp>
#include "AEntity.hpp"

using namespace std;
using namespace sf;

/**
 * @typedef Return a pointer on entity
 */
#define Builder function<AEntityPtr()>
/**
 * @typedef Return a pointer on entity from packet
 */
#define BuilderLoad function<AEntityPtr(Packet&)>

/**
 * @class EntityFactory "Include/EntityFactory.hpp"
 */
class EntityFactory
{
public:
    void addBuilder(const string &type, const Builder &builder, const BuilderLoad &builderLoad);
    AEntityPtr build(const string &type) const;
    AEntityPtr build(Packet &packet) const;

private:
    template<typename T>
    const T &getBuilder(const map<string, T> &map, const string &type) const;

private:
    map<string, Builder> builderMap;
    map<string, BuilderLoad> builderLoadMap;
};
