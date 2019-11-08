/**
 * @file      AudioManager.hpp
 * @brief     This class manages the music of the game
 */

#pragma once

#include <map>
#include <SFML/Audio.hpp>

/**
 * @class AudioManager "Include/AudioManager.hpp"
 */
class AudioManager {
public:
    AudioManager();
    ~AudioManager() = default;

public:
    void stopBackgroundMusic();
    bool playBackgroundMusic(const std::string &path);
    bool addSound(const std::string &name, const std::string &path);
    void playSound(const std::string &name);
    void stopSound(const std::string &name);

private:
    bool isPlaying;
    sf::Music backgroundMusic;
    std::map<std::string, sf::Sound> musics;
};
