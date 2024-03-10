#include <iostream>
#include <raylib.h>

#include "board.h"

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 450

int main(void)
{
    board::Board *board = new board::Board;
    board->__hello("C++");
    delete board;

    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "serpent");
    SetTargetFPS(60);

    int n_cell = (WINDOW_WIDTH - 20) / CELL_WIDTH;

    while (!WindowShouldClose()) {
        BeginDrawing();

        ClearBackground(BLACK);

        for (int i = 0; i < n_cell; i++) {
            int posx = (i * CELL_WIDTH) + 10;
            int endposx = posx + CELL_WIDTH;
            DrawLine(posx, 10, endposx, 10, RAYWHITE);
            DrawLine(posx, 10, posx, 10 + CELL_HEIGHT, RAYWHITE);
            DrawLine(posx + CELL_WIDTH, 10, posx + CELL_WIDTH, 10 + CELL_HEIGHT, RAYWHITE);
            DrawLine(posx, 10 + CELL_WIDTH, posx + CELL_WIDTH, 10 + CELL_WIDTH, RAYWHITE);
        }

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
