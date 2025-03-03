#pragma once

#include <iostream>
#include <thread>
#include <atomic>

#include "grid.hpp"
#include "pitcher.hpp"
#include "plate.hpp"
#include "canon.hpp"

namespace iron_dome_game
{
struct Game
{
    Game();
    ~Game() = default;

    void play();
    void keyboardListener();
    Grid grid;
    std::shared_ptr<Canon> canon;

    void spawnPlate();

    std::atomic<bool> isShotFired = false;
    std::atomic<bool> gameIsActive = false;

    static constexpr const int GAME_RUN_TIME_SEC = 20;

    // Statistics
    uint16_t platesFired = 0;
    uint16_t platesHit   = 0;
    uint16_t shotsFired  = 0;
};

}
