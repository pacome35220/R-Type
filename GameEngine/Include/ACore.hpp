/**
 * @file      ACore.hpp
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

/**
 * @class ACore "Include/ACore.hpp"
 * @brief     This is the abstract class of Core
 * @details   It will be inherited by core client and core server class (Core
 * package)
 * @details   It brings an abstraction for each of these classes because
 * client side won't exactly have the same methods than server side core
 */
class ACore: public ICore {
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
