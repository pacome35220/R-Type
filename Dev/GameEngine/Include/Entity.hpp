/*
** EPITECH PROJECT, 2019
** for_norme
** File description:
** Entity.hpp
*/

#pragma once

#include <string> // ?
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include "HaveId.hpp"

using namespace std;
using namespace sf;

#define EntityPtr unique_ptr<Entity>

class Entity : public HaveId // AEntity ?
{
public:
    Entity(const string &_type);
    Entity(const string &_type, Packet &packet);
    virtual ~Entity() = default; // ?
    // getPosition
    // move
    void update(); // virtual ? // virtual pur ?
    void aff(RenderTarget &renderTarget); // virtual ? // virtual pur ?

private:
    const string type; // string ?
    RectangleShape sprite; // RectangleShape or Sprite ?
    Vector2f position;
};
