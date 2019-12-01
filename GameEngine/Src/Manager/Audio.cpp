/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** Manager/Audio.cpp
*/

#include "Manager/Audio.hpp"

Manager::Audio::Audio(): isPlaying(false) {}

void Manager::Audio::stopBackgroundMusic() {
    if (this->isPlaying) {
        this->backgroundMusic.stop();
        this->isPlaying = false;
    }
}

bool Manager::Audio::playBackgroundMusic(const std::string &musicPath) {
    if (!this->isPlaying) {
        if (!this->backgroundMusic.openFromFile(musicPath))
            return false;
        this->backgroundMusic.play();
        this->isPlaying = true;
    }
    return this->isPlaying;
}

bool Manager::Audio::addSound(const std::string &name, const std::string
                                &path) {
    sf::SoundBuffer sound;

    if (!sound.loadFromFile(path))
        return false;
    this->musics[name].setBuffer(sound);
    return true;
}

void Manager::Audio::playSound(const std::string &name) {
    this->musics[name].play();
}

void Manager::Audio::stopSound(const std::string &name) {
    this->musics[name].stop();
}
