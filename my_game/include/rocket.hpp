#pragma once

#include "entity.hpp"

namespace iron_dome_game
{
struct Rocket : public Entity
{
    Rocket (uint16_t x_pos, uint16_t y_pos);
    ~Rocket() = default;

    EntityType type() override { return EntityType::ROCKET; }

    void drawOnGrid(Grid &grid) override;

    bool isStatic() { return false; }

};

}
