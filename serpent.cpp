#include <iostream>
#include <raylib.h>

#include "position.h"
#include "snake.h"

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 440

#define CELL_WIDTH 20
#define CELL_HEIGHT 20

int main(void)
{
    serpent::Snake snake;

    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "serpent");
    SetTargetFPS(60);

    int v = 0;
    int counter = 0;

    while (!WindowShouldClose()) {
        BeginDrawing();

        ClearBackground(BLACK);

        counter++;

        DrawRectangle(20, 0, CELL_WIDTH-1, CELL_HEIGHT-1, RED);

        DrawRectangle((v-20) % WINDOW_WIDTH, 0, CELL_WIDTH-1, CELL_HEIGHT-1, GREEN);
        DrawRectangle((v-40) % WINDOW_WIDTH, 0, CELL_WIDTH-1, CELL_HEIGHT-1, GREEN);
        DrawRectangle((v-60) % WINDOW_WIDTH, 0, CELL_WIDTH-1, CELL_HEIGHT-1, GREEN);
        DrawRectangle((v) % WINDOW_WIDTH, 0, CELL_WIDTH-1, CELL_HEIGHT-1, GREEN);

        if (counter >= 10) {
            v += 20;
            counter = 0;
        }

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
