#pragma once

#include <iostream>

namespace serpent
{
    namespace direction
    {
        enum Direction
        {
            DIRECTION_UP = 0,
            DIRECTION_DOWN,
            DIRECTION_LEFT,
            DIRECTION_RIGHT,
        };

        Direction to_opposite(Direction dir);
    }
}

