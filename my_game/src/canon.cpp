#include <iostream>
#include "canon.hpp"

namespace iron_dome_game 
{
    Canon::Canon()
    {
        trajectory.initialState.pos.x = 25;
        trajectory.initialState.pos.y = 0;
        trajectory.initialState.velocity.x = 0;
        trajectory.initialState.velocity.y = 0;

        width = 3;
        height = 5;
    }

//============================================================================//

void Canon::drawOnGrid(Grid &grid)
{
    auto col = pos().x;
    auto row = pos().y;

    grid.drawPixel(row, col  , '|');
    grid.drawPixel(row, col+1, ' ');
    grid.drawPixel(row, col+2, '|');

    grid.drawPixel(row+1, col  , '|');
    grid.drawPixel(row+1, col+1, ' ');
    grid.drawPixel(row+1, col+2, '|');

    grid.drawPixel(row+2, col  , '|');
    grid.drawPixel(row+2, col+1, ' ');
    grid.drawPixel(row+2, col+2, '|');

    grid.drawPixel(row+3, col  , '|');
    grid.drawPixel(row+3, col+1, ' ');
    grid.drawPixel(row+3, col+2, '|');

    grid.drawPixel(row+4, col  , '|');
    grid.drawPixel(row+4, col+1, ' ');
    grid.drawPixel(row+4, col+2, '|');

    grid.drawPixel(row+5, col  , '|');
    grid.drawPixel(row+5, col+1, '-');
    grid.drawPixel(row+5, col+2, '|');

}

    std::shared_ptr<Rocket> Canon::Fire() {
        auto x = trajectory.calculatePosition().x;
        auto y = height;
        std::cout << "Firing a rocket from position [" << x << '\n';

        return std::make_shared<Rocket>(x, y);
    }
}
