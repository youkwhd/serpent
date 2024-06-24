#include "snake.h"
#include "serpent.h"
#include "direction.h"
#include "position.h"
#include <vector>

namespace serpent
{

    Snake::Block::Block(serpent::Position pos, serpent::direction::Direction dir)
    {
        this->pos = pos;
        this->dir = dir;
    }

    Snake::Block::Block(serpent::Position pos) : Snake::Block(pos, serpent::direction::DIRECTION_RIGHT)
    {
    }

    Snake::Snake(Color color, std::uint16_t width, std::uint16_t height)
    {
        this->color = color;
        this->width = width;
        this->height = height;
    }

    Snake::Snake(std::uint16_t width, std::uint16_t height) : Snake(GREEN, width, height)
    {
    }

    Snake::Snake(): Snake(GREEN, BLOCK_WIDTH, BLOCK_HEIGHT)
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
        if (this->body.size() == 0) {
            this->body.push_back(Snake::Block(serpent::Position(1, 1)));
            return;
        }

        Snake::Block prev = this->tail();
        prev.pos.move(serpent::direction::to_opposite(prev.dir));

        this->body.push_back(prev);
    }

    void Snake::eat(std::uint16_t n)
    {
        while (n--) {
            Snake::eat();
        }
    }

    void Snake::draw()
    {
        for (serpent::Snake::Block &b : this->body) {
            DrawRectangle(b.pos.x * this->width, b.pos.y * this->height, this->width - 1, this->height - 1, this->color);
        }
    }

    void Snake::update_direction()
    {
        for (size_t i = this->body.size() - 1; i > 0; i--) {
            this->body[i].dir = this->body[i - 1].dir;
        }
    }

    bool Snake::is_head_collide()
    {
        Snake::Block &head = this->head();

        for (size_t i = 1; i < this->body.size(); i++) {
            if (head.pos == this->body[i].pos) {
                return true;
            }
        }

        return false;
    }

    void Snake::move()
    {
        for (serpent::Snake::Block &block : this->body) {
            block.pos.move(block.dir);
        }
    }

    void Snake::move(std::uint16_t max_x, std::uint16_t max_y)
    {
        for (serpent::Snake::Block &block : this->body) {
            block.pos.move(block.dir);

            block.pos.x = MOD(block.pos.x, max_x);
            block.pos.y = MOD(block.pos.y, max_y);
        }
    }
}
