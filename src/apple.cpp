#include "apple.h"
#include "serpent.h"

namespace serpent
{
    Apple::Apple(Color color, std::uint16_t width, std::uint16_t height)
    {
        this->color = color;
        this->width = width;
        this->height = height;
        this->reposition();
    }

    Apple::Apple(Color color) : Apple(color, BLOCK_WIDTH, BLOCK_HEIGHT)
    {
    }

    Apple::Apple() : Apple(RED)
    {
        this->reposition();
    }

    void Apple::draw()
    {
        DrawRectangle(this->pos.x * this->width, this->pos.y * this->height, this->width - 1, this->height - 1, this->color);
    }

    void Apple::reposition(std::uint16_t max_x, std::uint16_t max_y)
    {
        this->pos.x = MOD(std::rand(), max_x);
        this->pos.y = MOD(std::rand(), max_y);
    }

    void Apple::reposition()
    {
        this->pos.x = std::rand();
        this->pos.y = std::rand();
    }

    void Apple::reposition_and_avoid_snake(std::uint16_t max_x, std::uint16_t max_y, serpent::Snake &s)
    {
        this->reposition(max_x, max_y);

repeat:
        for (auto b : s.body) {
            if (this->pos == b.pos) {
                this->reposition(max_x, max_y);
                goto repeat;
            }
        }
    }
}
