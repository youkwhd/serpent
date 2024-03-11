#include "position.h"

namespace serpent
{
    Position::Position(int x, int y)
    {
        this->x = x;
        this->y = y;
    }

    void Position::move(Direction dir)
    {
        this->y += dir == DIRECTION_DOWN;
        this->y -= dir == DIRECTION_UP;
        this->x += dir == DIRECTION_RIGHT;
        this->x -= dir == DIRECTION_LEFT;
    }
}
