/*
** EPITECH PROJECT, 2018
**  <------------>
** File description:
**    <------->
*/

#pragma once

#include <cstddef>
#include <SFML/System/Clock.hpp>

class Clock {
public:
    Clock();
    ~Clock() = default;

    void tick();
    void frame();
    std::size_t getElapsedMicroseconds() const;
    std::size_t getElapsedMilliseconds() const;
    std::size_t getElapsedSeconds() const;
    std::size_t getTotalMicroseconds() const;
    std::size_t getTotalMilliseconds() const;
    std::size_t getTotalSeconds() const;

private:
    sf::Clock clock;
    std::size_t currentTime;
    std::size_t lastTime;
    std::size_t elapsedTime;
    std::size_t totalTime;
};
