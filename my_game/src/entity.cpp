#include "entity.hpp"

namespace iron_dome_game
{

Pos Entity::pos() 
{
    return isStatic() ? trajectory.initialState.pos : trajectory.calculatePosition(); 
}

//============================================================================//

BoundingBox Entity::boundingBox() 
{
    BoundingBox bbox;
    bbox.p1 = pos();
    bbox.p2.x = pos().x + width - 1;
    bbox.p2.y = pos().y + height - 1;

    return bbox;
}

bool Entity::hitGround() {
    auto pos = trajectory.calculatePosition();
    return !isStatic() && pos.y < 0;
}

}
