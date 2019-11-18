/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** AudioManager.cpp
*/

#include "Manager/AudioManager.hpp"

Manager::AudioManager::AudioManager() : isPlaying(false)
{}
bool Manager::AudioManager::playBackgroundMusic(const std::string &musicPath)
{
    if (!this->isPlaying) {
        if (!this->backgroundMusic.openFromFile(musicPath))
            return false;
        this->backgroundMusic.play();
        this->isPlaying = true;
    }
    return this->isPlaying;
}
void Manager::AudioManager::stopBackgroundMusic()
{
    if (this->isPlaying) {
        this->backgroundMusic.stop();
        this->isPlaying = false;
    }
}
bool Manager::AudioManager::addSound(const std::string &name, const std::string &path)
{
    sf::SoundBuffer sound;

    if (!sound.loadFromFile(path))
        return false;
    this->musics[name].setBuffer(sound);
    return true;
}
void Manager::AudioManager::playSound(const std::string &name)
{
    this->musics[name].play();
}
void Manager::AudioManager::stopSound(const std::string &name)
{
    this->musics[name].stop();
}
