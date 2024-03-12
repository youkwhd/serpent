#include <cmath>
#include <ctime>
#include <iostream>
#include <raylib.h>

#include "apple.h"
#include "direction.h"
#include "position.h"
#include "serpent.h"
#include "snake.h"

static bool paused = false;
static bool allowed_move = true;
static int counter = 0;

static serpent::Snake snake;
static serpent::Apple apple;

namespace serpent
{
    void draw()
    {
        BeginDrawing();
        ClearBackground(BLACK);

        DrawRectangle(apple.pos.x * BLOCK_WIDTH, apple.pos.y * BLOCK_HEIGHT, BLOCK_WIDTH-1, BLOCK_HEIGHT-1, apple.color);

        for (serpent::Snake::Block &b : snake.body) {
            DrawRectangle(b.pos.x * BLOCK_WIDTH, b.pos.y * BLOCK_HEIGHT, BLOCK_WIDTH-1, BLOCK_HEIGHT-1, snake.color);
        }

        counter++;

        EndDrawing();
    }

    void update()
    {
        if (IsKeyPressed(KEY_SPACE)) {
            paused = !paused;
        }

        if (paused) {
            return;
        }

        serpent::Snake::Block &__head = snake.head();

        if (allowed_move) {
            if (IsKeyPressed(KEY_W) && __head.dir != direction::to_opposite(direction::DIRECTION_UP)) {
                __head.dir = direction::DIRECTION_UP;
                allowed_move = false;
                goto q;
            }

            if (IsKeyPressed(KEY_A) && __head.dir != direction::to_opposite(direction::DIRECTION_LEFT)) {
                __head.dir = direction::DIRECTION_LEFT;
                allowed_move = false;
                goto q;
            }

            if (IsKeyPressed(KEY_S) && __head.dir != direction::to_opposite(direction::DIRECTION_DOWN)) {
                __head.dir = direction::DIRECTION_DOWN;
                allowed_move = false;
                goto q;
            }

            if (IsKeyPressed(KEY_D) && __head.dir != direction::to_opposite(direction::DIRECTION_RIGHT)) {
                __head.dir = direction::DIRECTION_RIGHT;
                allowed_move = false;
                goto q;
            }
        }

q:
        if (counter % 5 != 0) {
            return;
        }

        for (serpent::Snake::Block &b : snake.body) {
            b.pos.move(b.dir);

            b.pos.x = MOD(b.pos.x, MAX_X);
            b.pos.y = MOD(b.pos.y, MAX_Y);
        }

       snake.change_directions();

       if (snake.is_head_collide()) {
           paused = true;
           return;
       }

        if (__head.pos == apple.pos) {
            snake.eat();
            apple.reposition_and_avoid_snake(MAX_X, MAX_Y, snake);
        }

        allowed_move = true;
    }

    void init_game_state()
    {
        snake.eat(3);
        apple.reposition_and_avoid_snake(MAX_X, MAX_Y, snake);
    }

    void init_raylib()
    {
        InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "serpent");
        SetExitKey(KEY_Q);
        SetTargetFPS(60);
    }

    void deinit_raylib()
    {
        CloseWindow();
    }
}

int main(void)
{
    std::srand(std::time(nullptr));

    serpent::init_game_state();
    serpent::init_raylib();

    while (!WindowShouldClose()) {
        serpent::draw();
        serpent::update();
    }

    serpent::deinit_raylib();
    return 0;
}
