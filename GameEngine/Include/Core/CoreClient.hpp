/*
** EPITECH PROJECT, 2019
** for_norme
** File description:
** CoreClient.hpp
*/

#pragma once

#include "ACore.hpp"

class CoreClient : public ACore
{
public:
    CoreClient(const string &windowTitle);
    void run();
    void display(); // ?

private:
    void drawEntityMap();

private:
    RenderWindow window;
};
