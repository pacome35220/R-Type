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
#include "EntityList.hpp"
#include "Id.hpp"
#include "PacketType.hpp"

class ACore;
class AEntity;

typedef std::shared_ptr<AEntity> AEntityPtr;

/**
 * @class AEntity "Include/AEntity.hpp"
 */
class AEntity : public Id {
public:
    AEntity(sf::Vector2f position, std::string texturePath, ACore *entryPoint,
            enum EntityList _type);
    virtual ~AEntity() = default;
    const sf::Vector2f &getPosition() const;
    const sf::Sprite &getSprite() const;
    void setPosition(const sf::Vector2f &position);
    void setSprite(const sf::Sprite &sprite);

public:
    virtual void onCollision(AEntity *entity) = 0;
    virtual void update() = 0;

public:
    sf::Packet buildMyPacket(network::PacketType packetType);
    void updateFromPacket(sf::Packet packet);
    void render(sf::RenderWindow &window);

protected:
    enum EntityList type;
    std::string texturePath;
    sf::Texture texture;
    sf::Sprite sprite;
    ACore *entryPoint;
    sf::Vector2f position;
    size_t packetNumber;
};
