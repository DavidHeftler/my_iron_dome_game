#include "entity.hpp"

namespace iron_dome_game
{

Pos Entity::pos() 
{
    if (isStatic())
    {
        return trajectory.initialState.pos;
    }
    else
    {
        return trajectory.calculatePosition();
    }
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
    auto y_velocity = trajectory.initialState.velocity.y + GRAVITY * trajectory.duration().count(); // v(t) = v0 + a*t
    auto y_pos = trajectory.calculatePosition().y;

    return !isStatic() && y_velocity < 0 && y_pos <= 0;
}

}
