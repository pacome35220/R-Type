/**
 * @file      ACore.hpp
 * @brief     This is the Abstract Core
 * @details   This Abstract Class will be the parent of the CoreServer and
 * CoreClients classes.
 * @details   It brings an abstraction for each of these classes
 */

#pragma once

#include <vector>
//#include <SFML/Graphics.hpp> // ?
#include "AEntity.hpp"
#include "ICore.hpp"
#include "ActionManager.hpp"
#include "AudioManager.hpp"
#include "NetworkManager.hpp"

class ACore : public ICore {
public:
    ACore();
    virtual ~ACore() = default;

public:
    void
    setActionManager(std::shared_ptr<ActionManager> actionManager) override;
    void setCollisionManager(
        std::shared_ptr<CollisionManager> collisionManager) override;
    void
    setNetworkManager(std::shared_ptr<NetworkManager> networkManager) override;
    void setAudioManager(std::shared_ptr<AudioManager> audioManager) override;

    std::shared_ptr<AudioManager> getAudioManager() const override;
    std::shared_ptr<ActionManager> getActionManager() const override;
    std::shared_ptr<NetworkManager> getNetworkManager() const override;
    std::shared_ptr<CollisionManager> getCollisionManager() const override;

    AEntityPtr getEntityFromId(size_t id) override;

protected:
    std::size_t frameRate;
    bool canFeed;
    std::vector<AEntityPtr> entities;
    std::vector<AEntityPtr> deletionQueue;
    std::vector<std::size_t> topQueue;
    std::shared_ptr<ActionManager> actionManager;
    std::shared_ptr<AudioManager> audioManager;
    std::shared_ptr<CollisionManager> collisionManager;
    std::shared_ptr<NetworkManager> networkManager;

protected:
    void updateEntities() override;
    void procTopQueue();
};
