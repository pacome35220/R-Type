/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** Collision.cpp
*/

#include <iostream>
#include "Manager/Collision.hpp"


bool Manager::Collision::entityCollision(const AEntityPtr &entity1, const AEntityPtr &entity2)
{
    sf::FloatRect colliderRect = entity1->getSprite().getGlobalBounds();
    sf::FloatRect otherRect = entity2->getSprite().getGlobalBounds();

    return colliderRect.intersects(otherRect);
}

void Manager::Collision::processCollision(std::list<AEntityPtr> &entityList1, std::list<AEntityPtr> &entityList2)
{
    for (auto const &current: entityList1) {
        for (auto const &other: entityList2) {
            if (current->getId() == other->getId() ||
                current->getEntityType() == other->getEntityType())
                continue;
            if (this->entityCollision(current, other) || this->entityCollision(other, current)) {
                std::cout << "Collision match : " << current->getEntityType() << " - " << other->getEntityType() << std::endl;
                current->onCollision(other);
                other->onCollision(current);
            }
        }
    }
}

void Manager::Collision::detectCollision(const std::vector<AEntityPtr> &entityList)
{
    std::list<AEntityPtr> collider;

    if (entityList.size() < 3)
        return;
    for (auto &entity: entityList)
        if (entity->getEntityType() != EI_PARALLAX)
            collider.push_back(entity);
    std::cout << "Collision::detectCollision between " << collider.size() << " entities" << std::endl;
    this->processCollision(collider, collider);

}
