#include <ctime>
#include <iostream>
#include <raylib.h>

#include "apple.h"
#include "position.h"
#include "serpent.h"
#include "snake.h"

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
        if (counter < 8) {
            return;
        }

        for (serpent::Snake::Block &b : snake.body) {
            b.pos.move(b.dir);

            b.pos.x %= (WINDOW_WIDTH / 20);
            b.pos.y %= (WINDOW_HEIGHT / 20);
        }

        if (snake.head().pos.x == apple.pos.x && snake.head().pos.y == apple.pos.y) {
            apple.__reposition(snake, WINDOW_WIDTH / 20, WINDOW_HEIGHT / 20);
            snake.eat();
        }

        counter = 0;
    }
}

int main(void)
{
    std::srand(std::time(nullptr));

    serpent::Snake snake;
    serpent::Apple apple;

    snake.eat();
    apple.__reposition(snake, WINDOW_WIDTH / 20, WINDOW_HEIGHT / 20);

    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "serpent");
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        serpent::draw(snake, apple);
        serpent::update(snake, apple);
    }

    CloseWindow();
    return 0;
}
