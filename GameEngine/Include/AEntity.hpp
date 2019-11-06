/**
 * @file      AEntity.hpp
 * @brief     This class is the entity abstract class. It inherits from Id class
 * @brief     to get an unique ID for each entity
 * @details   It will be inherits by all the entities in the project
 * @details   (Monster, Asteroid, etc...)
 */

#pragma once

#include <string> // ?
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include "Id.hpp"
#include "CollisionManager.hpp"
#include "PacketType.hpp"

using namespace std;
using namespace sf;

#define AEntityPtr unique_ptr<AEntity>

class ACore;

class AEntity : public Id
{
public:
    AEntity(Vector2f &position, std::string texturePath, ACore *entryPoint);
    ~AEntity();
    const Vector2f &getPosition() const;
    const Sprite &getSprite() const;
    const CollisionManager &getCollisionManager() const;
    void setPosition(const Vector2f &position);
    void setSprite(const Sprite &sprite);

public:
    virtual void onCollision(AEntity *entity) = 0;
    virtual void update() = 0;

public:
    Packet buildMyPacket(network::PACKET_TYPE packetType);
    void updateFromPacket(Packet packet);
    void render();

private:
    Vector2f position;
    const std::string type;
    float angle;
    size_t packetNumber;

protected:
    std::string texturePath;
    Texture texture;
    Sprite sprite;
    CollisionManager collisionManager;
    ACore *entryPoint;
};
