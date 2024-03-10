#include "snake.h"
#include <vector>

namespace serpent
{
    Snake::Snake(Color color, std::uint16_t width, std::uint16_t height)
    {
        this->color = color;
        this->width = width;
        this->height = height;
    }

    Snake::Snake(std::uint16_t width, std::uint16_t height) : Snake(GREEN, width, height)
    {
    }

    Snake::Snake(): Snake(GREEN, 20, 20)
    {
    }
}
