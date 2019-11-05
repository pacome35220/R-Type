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
#include "AEntity.hpp"

using namespace std;
using namespace sf;

#define Builder function<AEntityPtr()>
#define BuilderLoad function<AEntityPtr(Packet&)>

class EntityFactory // template ?
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
