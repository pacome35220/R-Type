/*
** EPITECH PROJECT, 2019
** for_norme
** File description:
** CoreServer.hpp
*/

#pragma once

//#include <map> // ?
#include "ACore.hpp"

class CoreServer : public ACore
{
public:
    CoreServer() {};
    ~CoreServer() = default;
    void feedEntity(AEntityPtr entity);
    //void addEntity(AEntityPtr entity);
    //void removeEntity(AEntityPtr entity);
    void run();

private:
    //
};
