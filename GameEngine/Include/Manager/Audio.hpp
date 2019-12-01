/**
 * @file      Audio.hpp
 * @brief     This class manages the music of the game
 */

#pragma once

#include <map>
#include <SFML/Audio.hpp>

/**
 * @namespace Package to manage whole entities in the project
 */
namespace Manager {
    /**
     * @class Audio "Include/Manager/Audio.hpp"
    */
    class Audio {
    public:
        Audio();
        ~Audio() = default;

    public:
        void stopBackgroundMusic();
        bool playBackgroundMusic(const std::string &path);
        bool addSound(const std::string &name, const std::string &path);
        void playSound(const std::string &name);
        void stopSound(const std::string &name);

    private:
        bool isPlaying;
        sf::Music backgroundMusic;
        std::map <std::string, sf::Sound> musics;
    };
}

