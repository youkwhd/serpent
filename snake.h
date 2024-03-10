#pragma once

#include <cstdint>
#include <iostream>
#include <raylib.h>
#include <vector>

#include "position.h"

namespace serpent
{
    class Snake
    {
        /* size for each of the body parts
         */
        std::uint16_t width, height;

        Color color;
        std::vector<serpent::Position> body;

        public:
            Snake(Color color, std::uint16_t width, std::uint16_t height);
            Snake(std::uint16_t width, std::uint16_t height);
            Snake();
    };
}
