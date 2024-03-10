#include <ctime>
#include <iostream>
#include <raylib.h>

#include "apple.h"
#include "position.h"
#include "snake.h"

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 440

#define CELL_WIDTH 20
#define CELL_HEIGHT 20

int main(void)
{
    std::srand(std::time(nullptr));

    serpent::Snake snake;
    serpent::Apple apple;
    apple.pos.y = 1;

    snake.eat();

    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "serpent");
    SetTargetFPS(60);

    int counter = 0;

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK);

        DrawRectangle(apple.pos.x * 20, apple.pos.y * 20, CELL_WIDTH-1, CELL_HEIGHT-1, RED);

        counter++;

        for (serpent::Snake::Block &b : snake.body) {
            DrawRectangle(b.pos.x * 20, b.pos.y * 20, CELL_WIDTH-1, CELL_HEIGHT-1, snake.color);
        }

        if (counter >= 8) {
            for (serpent::Snake::Block &b : snake.body) {
                b.pos.move(b.dir);

                b.pos.x %= (WINDOW_WIDTH / 20);
                b.pos.y %= (WINDOW_HEIGHT / 20);
            }

            if (snake.head().pos.x == apple.pos.x && snake.head().pos.y == apple.pos.y) {
                snake.eat();
            }

            counter = 0;
        }

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
