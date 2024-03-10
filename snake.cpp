#include "snake.h"
#include "direction.h"
#include "position.h"
#include <vector>

namespace serpent
{

    Snake::Block::Block(serpent::Position pos, Direction dir)
    {
        this->pos = pos;
        this->dir = dir;
    }

    Snake::Block::Block(serpent::Position pos) : Snake::Block(pos, DIRECTION_RIGHT)
    {
    }

    Snake::Snake(Color color, std::uint16_t width, std::uint16_t height)
    {
        this->length = 0;
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

    Snake::Block &Snake::head()
    {
        return this->body.front();
    }

    Snake::Block &Snake::tail()
    {
        return this->body.back();
    }

    void Snake::eat()
    {
        if (this->length == 0) {
            this->body.push_back(Snake::Block(serpent::Position(1, 1)));
            this->length++;
            return;
        }

        Snake::Block prev = this->tail();
        prev.pos.move(serpent::direction::to_opposite(prev.dir));

        this->body.push_back(prev);
        this->length++;
    }

    void Snake::eat(std::uint16_t n)
    {
        while (n--) {
            Snake::eat();
        }
    }
}
