/**
 * @file      ACore.hpp
 * @brief     This is the Abstract Core
 * @details   This Abstract Class will be the parent of the Server and
 *            Clients classes.
 * @details   It brings an abstraction for each of these classes
 */

#pragma once

#include <vector>
#include "ICore.hpp"
#include "AEntity.hpp"
#include <Manager/Collision.hpp>
#include "Manager/Action.hpp"
#include "Manager/Audio.hpp"
#include "Manager/Network.hpp"
#include "Manager/Resource.hpp"

namespace Manager {
    class Audio;
    class Network;
    class Action;
    class Collision;
    class Resource;
}

class ACore : public ICore
{
public:
    ACore();
    virtual ~ACore() = default;
public:
    std::shared_ptr<Manager::Network> getNetwork() const;
    AEntityPtr getEntityFromId(size_t id) override;

public:
    void procTopQueue() override;
    void addToDeletionQueue(AEntityPtr entity) override;
    void addToDeletionQueue(std::size_t id) override;

protected:
    std::size_t frameRate;
    std::vector<AEntityPtr> entities;
    std::vector<AEntityPtr> deletionQueue;
    std::vector<std::size_t> topQueue;
    std::shared_ptr<Manager::Collision> collision;
    std::shared_ptr<Manager::Network> network;
};
