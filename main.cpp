#include <iostream>
#include <raylib.h>

#include "board.h"

#define WINDOW_WIDTH 700
#define WINDOW_HEIGHT 450

int main(void)
{
    board::Board *board = new board::Board;
    board->__hello("C++");
    delete board;

    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "serpent");
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        BeginDrawing();

        ClearBackground(BLACK);
        DrawLine(10, 10, 100, 10, WHITE);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
