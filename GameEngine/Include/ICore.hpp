/**
 * @file      ICore.hpp
 * @brief     This is the Core interface
 * @details   This interface will be the parent of the CoreServer and CoreClients classes.
 * @details   It brings an abstraction for each of these classes
 */

#pragma once

#include <memory>
#include "EntityID.hpp"

class AEntity;
typedef std::shared_ptr<AEntity> AEntityPtr;

namespace Manager {
class Audio;
class Network;
class Action;
class Collision;
class Resource;
}

/**
 * @interface ICore ICore.hpp "Include/ICore.hpp"
 */
class ICore {
public:
    virtual ~ICore() = default;
    virtual AEntityPtr getEntityFromId(std::size_t id) = 0;
    virtual void setAction(std::shared_ptr<Manager::Action> action) = 0;
    virtual void setCollision(std::shared_ptr<Manager::Collision> collision) = 0;
    virtual void setNetwork(std::shared_ptr<Manager::Network> network) = 0;
    virtual void setAudio(std::shared_ptr<Manager::Audio> audio) = 0;
    virtual void setResource(std::shared_ptr<Manager::Resource> resource) = 0;
    virtual std::shared_ptr<Manager::Audio> getAudio() const = 0;
    virtual std::shared_ptr<Manager::Action> getAction() const = 0;
    virtual std::shared_ptr<Manager::Network> getNetwork() const = 0;
    virtual std::shared_ptr<Manager::Collision> getCollision() const = 0;
    virtual std::shared_ptr<Manager::Resource> getResource() const = 0;

public:
    virtual void run() = 0;
    virtual void procDelectionQueue() = 0;
    virtual void updateEntities() = 0;
    virtual void procTopQueue() = 0;
	virtual void feedEntity(AEntityPtr entity) = 0;
    virtual void addToDeletionQueue(AEntityPtr entity) = 0;
    virtual void addToDeletionQueue(enum EntityID entityId) = 0;
};
