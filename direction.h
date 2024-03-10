#pragma once

#include <iostream>

namespace serpent
{
    namespace direction
    {
        enum Direction
        {
            DIRECTION_UP = 1 << 0,
            DIRECTION_DOWN = 1 << 1,
            DIRECTION_LEFT = 1 << 2,
            DIRECTION_RIGHT = 1 << 3,
        };

        Direction to_opposite(Direction dir);
    }
}

