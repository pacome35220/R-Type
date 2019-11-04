/*
** EPITECH PROJECT, 2019
** for_norme
** File description:
** EntityFactory.hpp
*/

#pragma once

#include <string> // ?
#include <functional>
#include <SFML/Network.hpp>
#include "Entity.hpp"

using namespace std;
using namespace sf;

#define Builder function<EntityPtr()>
#define BuilderLoad function<EntityPtr(Packet&)>

class EntityFactory // template ?
{
public:
    void addBuilder(const string &type, const Builder &builder, const BuilderLoad &builderLoad);
    EntityPtr build(const string &type) const;
    EntityPtr build(Packet &packet) const;

private:
    template<typename T>
    const T &getBuilder(const map<string, T> &map, const string &type) const;

private:
    map<string, Builder> builderMap;
    map<string, BuilderLoad> builderLoadMap;
};
