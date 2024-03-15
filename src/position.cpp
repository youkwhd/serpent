#include "position.h"

namespace serpent
{
    Position::Position(int x, int y)
    {
        this->x = x;
        this->y = y;
    }

    void Position::move(serpent::direction::Direction dir)
    {
        this->y += dir == serpent::direction::DIRECTION_DOWN;
        this->y -= dir == serpent::direction::DIRECTION_UP;
        this->x += dir == serpent::direction::DIRECTION_RIGHT;
        this->x -= dir == serpent::direction::DIRECTION_LEFT;
    }
}
