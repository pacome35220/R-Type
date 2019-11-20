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

/**
 * @interface ICore ICore.hpp "Include/ICore.hpp"
 */
class ICore {
public:
    virtual ~ICore() = default;

public:
    virtual AEntityPtr getEntityFromId(std::size_t id) = 0;
    virtual void run() = 0;
    virtual void procDelectionQueue() = 0;
    virtual void updateEntities() = 0;
    virtual void procTopQueue() = 0;
    virtual void feedEntity(AEntityPtr entity) = 0;
    virtual void addToDeletionQueue(AEntityPtr entity) = 0;
    virtual void addToDeletionQueue(std::size_t id) = 0;
};
