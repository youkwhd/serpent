#pragma once

#include "position.h"
#include "snake.h"

#include <cstdint>
#include <iostream>

#include <raylib.h>

namespace serpent
{
    class Apple
    {
        public:
            std::uint16_t width, height;
            Color color;
            serpent::Position pos;

            Apple(Color color, std::uint16_t width, std::uint16_t height);
            Apple(Color color);
            Apple();

            void draw();

            void reposition(std::uint16_t max_x, std::uint16_t max_y);
            void reposition();

            /* TODO: what the fuck is this?
             * cut the snake reference (use iterable)
             *
             * void reposition(std::uint16_t max_x, std::uint16_t max_y, ??::iterable<serpent::Position> avoid); 
             */
            void reposition_and_avoid_snake(std::uint16_t max_x, std::uint16_t max_y, serpent::Snake &s);
    };
}
