#pragma once 

#include "rocket.hpp"

namespace iron_dome_game {
struct Canon : public Entity
{
    Canon();
    ~Canon() = default;

    EntityType type() override { return EntityType::CANNON; }

    void drawOnGrid(Grid& grid) override;

    bool isStatic() { return true; }

    std::shared_ptr<Rocket> Fire();
};
};
