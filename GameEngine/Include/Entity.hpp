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

class ACore;

class Entity : public HaveId // AEntity ?
{
public:
    Entity(ACore &_core, const string &_type);
    Entity(ACore &_core, const string &_type, Packet &packet);
    virtual ~Entity() = default; // ?
    const string &getType() const;
    const size_t &getHp() const;
    const Vector2f &getPosition() const;
    const float &getAngle() const;
    virtual void update() = 0; // Param ?
    virtual void onCollision(Entity &other) = 0; // class HaveCollision ?
    void aff(RenderTarget &renderTarget); // name ? // virtual ?

protected:
    ACore &core;
    const string type; // string ?
    RectangleShape sprite; // RectangleShape or Sprite ? // server ??
    size_t hp;
    Vector2f position;
    float angle;
};
