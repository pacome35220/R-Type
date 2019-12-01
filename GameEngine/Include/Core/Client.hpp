/**
 * @file      Core/Client.hpp
 */

#pragma once

#include "ACore.hpp"

/**
 * @namespace Core
 * @brief To manage the entity on client or server side
 */
namespace Core {
    /**
     * @class Client "Include/Core/Client.hpp"
     * @brief This class manages all the client side ACore methods
    */
    class Client: public ACore {
    public:
        Client(const std::string &windowTitle);
        const sf::RenderWindow &getRenderWindow() const;
        std::shared_ptr<Manager::Audio> getAudio() const;
        std::shared_ptr<Manager::Resource> getResource() const;

    public:
        void run() override;
        void updateEntities() override;
        void procDeletionQueue() override;
        void feedEntity(AEntityPtr entity) override;

    private:
        void renderEntities();
        void handleWindowEvent();

    private:
        sf::RenderWindow window;
        std::shared_ptr<Manager::Action> action;
        std::shared_ptr<Manager::Audio> audio;
        std::shared_ptr<Manager::Resource> resource;
    };
}
