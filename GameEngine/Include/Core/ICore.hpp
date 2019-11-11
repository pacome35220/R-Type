/**
 * @file      ICore.hpp
 * @brief     This is the Core interface
 * @details   This interface will be the parent of the CoreServer and CoreClients classes.
 * @details   It brings an abstraction for each of these classes
 */

#pragma once

class AEntity;

typedef std::shared_ptr<AEntity> AEntityPtr;

class AudioManager;
class NetworkManager;
class ActionManager;
class CollisionManager;

/**
 * @interface ICore ICore.hpp "Include/ICore.hpp"
 */
class ICore {
public:
    virtual ~ICore() = default;
    virtual AEntityPtr getEntityFromId(std::size_t id) = 0;
    virtual void setActionManager(std::shared_ptr<ActionManager> actionManager) = 0;
    virtual void setCollisionManager(std::shared_ptr<CollisionManager> collisionManager) = 0;
    virtual void setNetworkManager(std::shared_ptr<NetworkManager> networkManager) = 0;
    virtual void setAudioManager(std::shared_ptr<AudioManager> audioManager) = 0;

    virtual std::shared_ptr<AudioManager> getAudioManager() const = 0;
	virtual std::shared_ptr<ActionManager> getActionManager() const = 0;
	virtual std::shared_ptr<NetworkManager> getNetworkManager() const = 0;
	virtual std::shared_ptr<CollisionManager> getCollisionManager() const = 0;

    //virtual void setOnTop(int id) = 0;

public:
    virtual void addEntity(AEntityPtr entity) = 0;
    // virtual void addToDeletionQueue(AEntityPtr entity) = 0;
    // virtual void addDeletionQueueById(int id) = 0; //param id ?
    // virtual void authorizeFeed(bool auth) = 0;
    // virtual void authorizeRender(bool auth) = 0;
    // virtual float absoluteToRelativeX(float x) = 0;
    // virtual float absoluteToRelativeY(float y) = 0;
    // virtual float absoluteToAbsoluteX(float x) = 0;
    // virtual float absoluteToAbsoluteY(float y) = 0;
    virtual void run() = 0;
    virtual void procDelectionQueue() = 0;
    virtual void updateEntities() = 0;
    virtual void procTopQueue() = 0;
};
