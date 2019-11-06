/*
** EPITECH PROJECT, 2019
** for_norme
** File description:
** CoreClient.cpp
*/

#include <iostream>
#include "Core/CoreClient.hpp"

CoreClient::CoreClient(const string &windowTitle)
    : window(VideoMode::getDesktopMode(), windowTitle, Style::Fullscreen) // TODO add antialiasing ? (if rotate)
{
}

void CoreClient::run()
{
    while (window.isOpen()) {
        // TODO
        std::cout << "hey client !" << std::endl;
        display();
    }
}

void CoreClient::display()
{
    drawEntityMap();
}

void CoreClient::drawEntityMap()
{
    // TODO
}
