/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** Classic.cpp
*/

#include "Monster/Classic.hpp"

Monster::Classic::Classic(ACore &entryPoint, const sf::Vector2f &position,
                          float speed, float amplitude, float amplitudeSpeed,
                          float scale)
    : AMonster(position, entryPoint, EI_CLASSIC_MONSTER, speed, amplitude,
               amplitudeSpeed, scale) {}

void Monster::Classic::onDeath() {
    float speed = (float)(std::rand() % 200) / 100;
    float amplitude = (float)(std::rand() % 1000) / 100;
    float amplitudeSpeed = (float)(std::rand() % 5) / 100;

    this->entryPoint.addToDeletionQueue(this->getId());
    this->entryPoint.feedEntity(std::make_shared<Monster::Classic>(
        this->entryPoint, sf::Vector2f(100, 0), speed, amplitude,
        amplitudeSpeed, this->scale));
}
