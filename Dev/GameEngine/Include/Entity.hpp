/*
** EPITECH PROJECT, 2019
** for_norme
** File description:
** Entity.hpp
*/

#pragma once

#include <string> // ?
#include <SFML/Graphics.hpp>
#include "HaveId.hpp"

using namespace std;
using namespace sf;

class Entity : public HaveId // HaveId ?? (server OK / client KO)
{
public:
    Entity(const string &_type);
    virtual ~Entity() = default;
    // getPosition
    // move
    void update(); // virtual ? // virtual pur ?
    void aff(RenderTarget &renderTarget); // virtual ? // virtual pur ?

private:
    const string type; // string ?
    RectangleShape sprite; // RectangleShape or Sprite ?
    Vector2f position;
};

// TODO move in .cpp
Entity::Entity(const string &_type)
    : type(_type)
{
}
