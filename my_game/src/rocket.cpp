#include "rocket.hpp"

namespace iron_dome_game {
    Rocket::Rocket(uint16_t x_pos, uint16_t y_pos) {
       trajectory.initialState.pos.x = x_pos; 
       trajectory.initialState.pos.y = y_pos; 
       trajectory.initialState.velocity.x = 70;
       trajectory.initialState.velocity.y = 15;

       width   = 3;
       height  = 3;
    }

    void Rocket::drawOnGrid(Grid& grid) {

        auto col = pos().x;
        auto row = pos().y;

        grid.drawPixel(row, col,   '\\');
        grid.drawPixel(row, col+1, '_');
        grid.drawPixel(row, col+2, '/');

        grid.drawPixel(row+1, col  , '|');
        grid.drawPixel(row+1, col+1, '*');
        grid.drawPixel(row+1, col+2, '|');

        grid.drawPixel(row+2, col  , '/');
        grid.drawPixel(row+2, col+1, '^');
        grid.drawPixel(row+2, col+2, '\\');
    }
}

        


