#pragma once

#include <cstdint>
#include <iostream>
#include <raylib.h>
#include <vector>

#include "direction.h"
#include "position.h"

namespace serpent
{
    class Snake
    {
        /* size for each of the body parts
         */
        std::uint16_t width, height;

        public:
            class Block
            {
                public:
                    serpent::Position pos;
                    serpent::direction::Direction dir;

                    Block(serpent::Position pos, serpent::direction::Direction dir);
                    Block(serpent::Position pos);
            };

            Color color;
            std::vector<serpent::Snake::Block> body;

            Snake(Color color, std::uint16_t width, std::uint16_t height);
            Snake(std::uint16_t width, std::uint16_t height);
            Snake();

            Block &head();
            Block &tail();

            void eat();
            void eat(std::uint16_t n);

            void draw();

            void move();
            void move(std::uint16_t max_x, std::uint16_t max_y);

            void update_direction();
            bool is_head_collide();
    };
}
