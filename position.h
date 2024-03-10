#pragma once

#include <iostream>
#include "direction.h"

using namespace serpent::direction;

namespace serpent
{
    class Position
    {
        public:
            int x, y;

            Position(int x = 0, int y = 0);
            void move(Direction dir);

            inline bool operator==(const Position& p) { return p.x == x && p.y == y; }
    };
}

