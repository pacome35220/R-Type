/**
 * @file      AEntity.hpp
 * @brief     This class is the entity abstract class. It inherits from Id class
 * @brief     to get an unique ID for each entity
 * @details   It will be inherits by all the entities in the project
 * @details   (Monster, Asteroid, etc...)
 */

#pragma once

#include <memory>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include "EntityID.hpp"
#include "Id.hpp"
#include "PacketType.hpp"

/**
 * @brief We don't need to import all the class, just need to know they exist
 */
class ACore;
class AEntity;

typedef std::shared_ptr <AEntity> AEntityPtr;

/**
 * @class AEntity "Include/AEntity.hpp"
 */
class AEntity: public Id {
public:
    AEntity(const sf::Vector2f &position, ACore &entryPoint,
            enum EntityID type);
    virtual ~AEntity() = default;
    sf::Texture &getTexture();
    sf::Sprite &getSprite();
    int getStreamTimer();
    enum EntityID getEntityType();

public:
    virtual void onCollision(AEntityPtr entity) = 0;
    virtual void update() = 0;
    virtual void increaseStreamTimer();
    void resetStreamTimer();

public:
    virtual sf::Packet buildMyAsAPacket(network::PacketType packetType);
    void updateFromPacket(sf::Packet packet);
    void render(sf::RenderWindow &window);

private:
    sf::Vector2f absoluteToRelativePosition(sf::Vector2u window);

protected:
    enum EntityID type;
    sf::Texture texture;
    sf::Sprite sprite;
    ACore &entryPoint;
    sf::Vector2f position;
    size_t packetNumber;
    int health;
    int streamTimer;
};
