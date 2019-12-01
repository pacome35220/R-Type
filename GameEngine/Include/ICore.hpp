/**
 * @file      ICore.hpp
 */

#pragma once

#include <memory>
#include "EntityID.hpp"

class AEntity;

typedef std::shared_ptr<AEntity> AEntityPtr;

/**
 * @interface ICore ICore.hpp "Include/ICore.hpp"
 * @brief     This is the Core interface
 * @details   This interface will be the parent of the Core package class.
 * It brings an abstraction for each of these classes
 */
class ICore {
public:
    virtual ~ICore() = default;

public:
    virtual AEntityPtr getEntityFromId(std::size_t id) = 0;
    virtual void run() = 0;
    virtual void procDeletionQueue() = 0;
    virtual void updateEntities() = 0;
    virtual void feedEntity(AEntityPtr entity) = 0;
    virtual void addToDeletionQueue(AEntityPtr entity) = 0;
    virtual void addToDeletionQueue(std::size_t id) = 0;
};
