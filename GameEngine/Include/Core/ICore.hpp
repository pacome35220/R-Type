/**
 * @file      ICore.hpp
 * @brief     This is the Core interface
 * @details   This interface will be the parent of the CoreServer and CoreClients classes.
 * @details   It brings an abstraction for each of these classes
 */

#pragma once

class AEntity;

typedef std::unique_ptr<AEntity> AEntityPtr;

class AudioManager;
class NetworkManager;
class ActionManager;
class CollisionManager;

/**
 * @interface ICore ICore.hpp "Include/ICore.hpp"
 */
class ICore {
public:
    // virtual AudioManager *getAudioManager() = 0;
    // virtual ActionManager *getActionManager() = 0;
    // virtual Vector2i getScreenSize() const = 0;
    // virtual RenderWindow *getRenderWindow() = 0;
    // virtual NetworkManager *getNetworkManager() const = 0;
    // virtual CollisionManager getCollisionManager() = 0;
    // virtual AEntity *getEntityFromId(int id) = 0;
    // virtual void setActionManager(std::shared_ptr<ActionManager>) = 0;
    // virtual void setCollisionManager(std::shared_ptr<CollisionManager>) = 0;
    // virtual void setNetworkManager(std::shared_ptr<NetworkManager>) = 0;
    // virtual void setAudioManager(std::shared_ptr<AudioManager>) = 0;
    // virtual void setOnTop(int id) = 0;

public:
    virtual void addEntity(AEntityPtr entity) = 0;
    virtual void removeEntity(AEntityPtr entity) = 0;
    // virtual void feedEntity(AEntityPtr entity) = 0;
    // virtual void addToDeletionQueue(AEntityPtr entity) = 0;
    // virtual void addDeletionQueueById(int id) = 0; //param id ?
    // virtual void authorizeFeed(bool auth) = 0;
    // virtual void authorizeRender(bool auth) = 0;
    // virtual float absoluteToRelativeX(float x) = 0;
    // virtual float absoluteToRelativeY(float y) = 0;
    // virtual float absoluteToAbsoluteX(float x) = 0;
    // virtual float absoluteToAbsoluteY(float y) = 0;
    virtual void run() = 0;
};
