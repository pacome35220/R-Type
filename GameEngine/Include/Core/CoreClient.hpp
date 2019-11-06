/*
** EPITECH PROJECT, 2019
** for_norme
** File description:
** CoreClient.hpp
*/

#pragma once

//#include <map> // ?
#include "ACore.hpp"

class CoreClient : public ACore
{
public:
    Core(const string &windowTitle);
    void run();
    void display(); // ?

private:
    void drawEntityMap();

private:
    RenderWindow window;
};
