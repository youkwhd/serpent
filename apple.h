#pragma once

#include "position.h"
#include "snake.h"

#include <cstdint>
#include <iostream>

namespace serpent
{
    class Apple
    {
        public:
            std::uint16_t width, height;
            serpent::Position pos;

            Apple();
            void reposition(std::uint16_t max_x, std::uint16_t max_y);
            void reposition();

            /* TODO: what the fuck is this?
             * cut the snake reference (use iterable)
             */
            void reposition_and_avoid_snake(std::uint16_t max_x, std::uint16_t max_y, serpent::Snake &s);
    };
}
