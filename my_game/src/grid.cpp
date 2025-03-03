#include <iostream>
#include <unordered_set>
#include "grid.hpp"
#include "entity.hpp"

namespace iron_dome_game
{

void Grid::draw() 
{
    for (int i = GRID_ROWS - 1; i >= 0; --i)
    {
        for (int j = 0; j < GRID_COLUMNS; ++j)
        {
            std::cout << m_grid[i][j];
        }
        std::cout << std::endl;
    }

}

//============================================================================//

void Grid::refresh() 
{
    // Draw background
    forEveryPixel(
        [this](int row, int col)
        {
            m_grid[row][col] = ' ';
        }
    );

    // Draw ground
    forEveryPixel(
        [this](int row, int col)
        {
            m_grid[row][col] = '_';
        },
        1
    );

    m_entities.remove_if([](std::shared_ptr<Entity> entity) {
            return entity->hitGround();
            }); 


    for (auto entity : m_entities)
    {
        entity->drawOnGrid(*this);
    }
}

//============================================================================//

bool Grid::drawPixel(uint16_t row, uint16_t col, char pixel) 
{
    if (row >= 0 && row < rows() && col >= 0 && col < columns() && pixel != ' ')
    {
        m_grid[row][col] = pixel;
        return true;
    }
    return false;
}

//============================================================================//

void Grid::forEveryPixel(std::function<void(int row, int col)> function, const int rowCount, const int columnCount) 
{
    for (int i = 0; i < rowCount; ++i)
    {
        for (int j = 0; j < columnCount; ++j)
        {
            function(i, j);
        }
    }
}

//============================================================================//

uint16_t Grid::checkHits() 
{
    uint16_t hits = 0;

    std::unordered_set<std::shared_ptr<Entity>> to_remove;

    std::list<std::shared_ptr<Entity>> rockets, plates;

    for (auto entity : m_entities) {
        if (entity->type() == EntityType::ROCKET) {
            rockets.push_back(entity);
        } else if (entity->type() == EntityType::PLATE) {
            plates.push_back(entity);
        } 
    }   
            
    auto rocket_it = rockets.begin();
    while (rocket_it != rockets.end()) {

        auto plate_it = plates.begin();
        bool intersected = false;

        while (plate_it != plates.end()) {
            if (intersects(*rocket_it, *plate_it)) {

                to_remove.insert(*rocket_it);
                to_remove.insert(*plate_it);

                plates.erase(plate_it); // assume a plate gets hit at most once
                intersected = true;
                break; 
            } 

            plate_it++;
            
        }

        if (intersected) {
            rocket_it = rockets.erase(rocket_it); // assume a rocket can hit one plate (and is destroyed)
            hits++;
            continue;
        } 

        rocket_it++;
        
    }
    
    m_entities.remove_if([&to_remove](const std::shared_ptr<Entity>& ptr) {
        return to_remove.find(ptr) != to_remove.end();
    });


    return hits;
}

//============================================================================//

bool Grid::intersects(std::shared_ptr<Entity> e1, std::shared_ptr<Entity> e2) 
{

    bool x_overlap = (e1->pos().x < e2->pos().x + e2->width) &&
                    (e2->pos().x < e1->pos().x + e1->width);


    bool y_overlap = (e1->pos().y < e2->pos().y + e2->height) &&
                    (e2->pos().y < e1->pos().y + e1->height);

    return x_overlap && y_overlap;
}

}
