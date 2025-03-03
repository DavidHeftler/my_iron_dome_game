#pragma once

#include "config.hpp"
#include "grid.hpp"
#include "trajectory.hpp"

namespace iron_dome_game
{
enum EntityType
{
    NONE,
    PITCHER,
    CANNON,
    PLATE,
    ROCKET
};

struct Entity
{
    Trajectory trajectory;
    uint16_t width = 0;
    uint16_t height = 0;

    virtual ~Entity() = default; // Ensure proper cleanup

    virtual EntityType type() { return EntityType::NONE; }

    Pos pos();

    BoundingBox boundingBox();

    virtual bool isStatic() = 0;
    
    virtual void drawOnGrid(Grid &grid) = 0;

    bool hitGround();
};
}
