#pragma once

#include <cstdint>
#include <iostream>
#include <raylib.h>
#include <vector>

#include "direction.h"
#include "position.h"

using namespace serpent::direction;

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
                    Direction dir;

                    Block(serpent::Position pos, Direction dir);
                    Block(serpent::Position pos);
            };

            Color color;
            std::vector<serpent::Snake::Block> body;

            /* TODO: is this really worth the cost?
             * could be dangerous if forgotten to update.
             */
            std::uint16_t length;

            Snake(Color color, std::uint16_t width, std::uint16_t height);
            Snake(std::uint16_t width, std::uint16_t height);
            Snake();

            Block &head();
            Block &tail();

            void eat();
            void eat(std::uint16_t n);

            void change_directions();
            bool is_head_collide();
    };
}
