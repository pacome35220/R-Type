/**
 * @file      Audio.hpp
 */

#pragma once

#include <map>
#include <SFML/Audio.hpp>

/**
 * @namespace Manager
 * @brief To manage whole entities
 */
namespace Manager {
    /**
     * @class Audio "Include/Manager/Audio.hpp"
     * @brief Aduio manages the music of the game
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
        std::map<std::string, sf::Sound> musics;
    };
}

