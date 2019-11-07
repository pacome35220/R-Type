/**
 * @file      ACore.hpp
 * @brief     This is the Abstract Core
 * @details   This Abstract Class will be the parent of the CoreServer and CoreClients classes.
 * @details   It brings an abstraction for each of these classes
 */

#pragma once

#include <vector>
//#include <SFML/Graphics.hpp> // ?
#include "AEntity.hpp"
#include "ICore.hpp" 

class ACore : public ICore {
public:
    ACore() {};
    virtual ~ACore() = default;

public:
    void addEntity(AEntityPtr entity);
    void removeEntity(AEntityPtr entity);

protected:
    int frameRate;
    bool canRender;
    bool canFeed;
    Vector2i screenSize;
    std::vector<AEntityPtr> sprites;
    std::vector<AEntityPtr> deletionQueue;
    std::vector<int> topQueue;
    RenderWindow *window;
    AudioManager *audioManager;
    CollisionManager *collisionManager;
    NetworkManager *networkManager;

private:
    void updateEntities();
    void renderEntities();
    void streamEntityFeed();
    void handleWindow();
    void procTopQueue();
};
