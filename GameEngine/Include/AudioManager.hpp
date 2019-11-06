/**
 * @file      AudioManager.hpp
 * @brief     This class manages the music of the game
 */


#pragma once

#include <SFML/Audio.hpp>

using namespace sf;

/**
 * @class AudioManager AudioManager.hpp "Include/AudioManager.hpp"
 */
class AudioManager
{
public:
    AudioManager();
    ~AudioManager();

public:
    void stopBackgroundMusic();
    bool playBackgroundMusic(const std::string musicPath);
    bool playSound(const std::string soundPath);

private:
    bool isPlaying;
    Music backgroundMusic;
};
