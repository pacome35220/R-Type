/*
** EPITECH PROJECT, 2019
** for_norme
** File description:
** Core.hpp
*/

#pragma once

//#include <map> // ?
#include "ACore.hpp"

class Core : public ACore
{
public:
    Core(const string &windowTitle);
    void display(); // ?

private:
    void drawEntityMap();

private:
    RenderWindow window;
};
