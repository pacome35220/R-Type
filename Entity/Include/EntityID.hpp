/**
 * @file      EntityID.hpp
 * @brief     This file has the enum of the entities availables in our game.
 */

#pragma once

/**
 * @enum Define and refer to entities's types
 */
enum EntityID {
    EI_UNKNOWN = -1,
    EI_CLASSIC_MONSTER,
    EI_DUMB_MONSTER,
    EI_SPEED_MONSTER,
    EI_ANGRY_MONSTER,
    EI_DOLLEY_MONSTER,

    EI_DEATH_STAR,
    EI_ASTEROID,

    EI_DEATH_STAR_BULLET,
    EI_MONSTER_BULLET,
    EI_PLAYER_BULLET,

    EI_PARALLAX,

    EI_POWER_UP,
    EI_HEALTH_UP,

    EI_PLAYER,
    EI_PLAYER1,
    EI_PLAYER2,
    EI_PLAYER3,
    EI_PLAYER4,

    EI_TOTAL_NUMBER
};
