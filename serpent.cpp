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

namespace serpent
{
    void draw(serpent::Snake &snake, serpent::Apple &apple)
    {
        BeginDrawing();
        ClearBackground(BLACK);

        DrawRectangle(apple.pos.x * 20, apple.pos.y * 20, CELL_WIDTH-1, CELL_HEIGHT-1, RED);

        for (serpent::Snake::Block &b : snake.body) {
            DrawRectangle(b.pos.x * 20, b.pos.y * 20, CELL_WIDTH-1, CELL_HEIGHT-1, snake.color);
        }

        counter++;

        EndDrawing();
    }

    void update(serpent::Snake &snake, serpent::Apple &apple)
    {
        if (IsKeyPressed(KEY_SPACE)) {
            paused = !paused;
        }

        if (paused) {
            return;
        }

        serpent::Snake::Block &__head = snake.head();

        if (allowed_move) {
            if (IsKeyPressed(KEY_W) && __head.dir != direction::DIRECTION_DOWN) {
                __head.dir = direction::DIRECTION_UP;
                allowed_move = false;
                goto q;
            }

            if (IsKeyPressed(KEY_A) && __head.dir != direction::DIRECTION_RIGHT) {
                __head.dir = direction::DIRECTION_LEFT;
                allowed_move = false;
                goto q;
            }

            if (IsKeyPressed(KEY_S) && __head.dir != direction::DIRECTION_UP) {
                __head.dir = direction::DIRECTION_DOWN;
                allowed_move = false;
                goto q;
            }

            if (IsKeyPressed(KEY_D) && __head.dir != direction::DIRECTION_LEFT) {
                __head.dir = direction::DIRECTION_RIGHT;
                allowed_move = false;
                goto q;
            }
        }
        /* if (counter < 8) { */
        /*     return; */
        /* } */

q:
        if (counter % 5 != 0) {
            return;
        }

        for (serpent::Snake::Block &b : snake.body) {
            b.pos.move(b.dir);

            b.pos.x = MOD(b.pos.x, WINDOW_WIDTH / 20);
            b.pos.y = MOD(b.pos.y, WINDOW_HEIGHT / 20);
        }

       snake.move();

        for (int i = 1; i < snake.length; i++) {
            if (__head.pos == snake.body[i].pos) {
                paused = true;
                break;
            }
        }

        if (__head.pos == apple.pos) {
            apple.__reposition(snake, WINDOW_WIDTH / 20, WINDOW_HEIGHT / 20);
            snake.eat();
        }

        allowed_move = true;
    }
}

int main(void)
{
    std::srand(std::time(nullptr));

    serpent::Snake snake;
    serpent::Apple apple;

    snake.eat(10);
    apple.__reposition(snake, WINDOW_WIDTH / 20, WINDOW_HEIGHT / 20);

    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "serpent");
    SetExitKey(KEY_Q);
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        serpent::draw(snake, apple);
        serpent::update(snake, apple);
    }

    CloseWindow();
    return 0;
}
