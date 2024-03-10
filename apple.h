#pragma once

#include "position.h"
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
    };
}
