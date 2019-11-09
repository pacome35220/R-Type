/*
** EPITECH PROJECT, 2018
**  <------------>
** File description:
**    <------->
*/

#include "Clock.hpp"

Clock::Clock() : currentTime(0), lastTime(0), elapsedTime(0), totalTime(0) {
    this->tick();
}

void Clock::tick() {
    this->currentTime = this->clock.getElapsedTime().asMicroseconds();
    if (!this->lastTime)
        this->lastTime = this->currentTime;
    this->elapsedTime += this->currentTime - this->lastTime;
    this->totalTime += this->currentTime - this->lastTime;
    this->lastTime = this->currentTime;
}

void Clock::frame() {
    this->elapsedTime = 0;
}

std::size_t Clock::getElapsedMicroseconds() const {
    return this->elapsedTime;
}

std::size_t Clock::getElapsedMilliseconds() const {
    return this->elapsedTime * 1e-3;
}

std::size_t Clock::getElapsedSeconds() const {
    return this->elapsedTime * 1e-6;
}

std::size_t Clock::getTotalMicroseconds() const {
    return this->totalTime;
}

std::size_t Clock::getTotalMilliseconds() const {
    return this->totalTime * 1e-3;
}

std::size_t Clock::getTotalSeconds() const {
    return this->totalTime * 1e-6;
}
