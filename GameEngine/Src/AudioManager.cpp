/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** AudioManager.cpp
*/

#include "AudioManager.hpp"

AudioManager::AudioManager() : isPlaying(false) {}

bool AudioManager::playBackgroundMusic(const std::string &musicPath) {
    if (!this->isPlaying) {
        if (!this->backgroundMusic.openFromFile(musicPath))
            return false;
        this->backgroundMusic.play();
        this->isPlaying = true;
    }
    return this->isPlaying;
}

void AudioManager::stopBackgroundMusic() {
    if (this->isPlaying) {
        this->backgroundMusic.stop();
        this->isPlaying = false;
    }
}

bool AudioManager::addSound(const std::string &name, const std::string &path) {
    sf::SoundBuffer sound;

    if (!sound.loadFromFile(path))
        return false;
    this->musics[name].setBuffer(sound);
    return true;
}

void AudioManager::playSound(const std::string &name) {
    this->musics[name].play();
}

void AudioManager::stopSound(const std::string &name) {
    this->musics[name].stop();
}
