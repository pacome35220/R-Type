/*
** EPITECH PROJECT, 2019
** for_norme
** File description:
** Core.cpp
*/

#include "Core/Core.hpp"

Core::Core(const string &windowTitle)
    : window(VideoMode::getDesktopMode(), windowTitle, Style::Fullscreen) // TODO add antialiasing ? (if rotate)
{
}

void Core::display()
{
    drawEntityMap();
}

void Core::drawEntityMap()
{
    for (const auto &entityTuple : entityMap)
        entityTuple.second->aff(window);
}