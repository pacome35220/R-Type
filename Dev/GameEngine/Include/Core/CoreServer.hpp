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
    void addEntity(EntityPtr &entity);
    void removeEntity(EntityPtr &entity);

private:
    //
};
