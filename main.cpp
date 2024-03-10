#include <iostream>
#include <raylib.h>

#include "board.h"

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 440

int main(void)
{
    board::Board *board = new board::Board;
    board->__hello("C++");
    delete board;

    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "serpent");
    SetTargetFPS(60);

    int n_cell = (WINDOW_WIDTH - 20) / CELL_WIDTH;
    int board_height = (WINDOW_HEIGHT - 20) / CELL_HEIGHT;

    while (!WindowShouldClose()) {
        BeginDrawing();

        ClearBackground(BLACK);

        for (int i = 0; i < board_height; i++) {
            int posy = (i * CELL_HEIGHT) + 10;

            for (int j = 0; j < n_cell; j++) {
                int posx = (j * CELL_WIDTH) + 10;

                DrawLine(posx, posy, posx + CELL_WIDTH, posy, RAYWHITE);
                DrawLine(posx, posy, posx, posy + CELL_HEIGHT, RAYWHITE);
                DrawLine(posx + CELL_WIDTH, posy, posx + CELL_WIDTH, posy + CELL_HEIGHT, RAYWHITE);
                DrawLine(posx, posy + CELL_WIDTH, posx + CELL_WIDTH, posy + CELL_WIDTH, RAYWHITE);
            }
        }

        EndDrawing();
    }

    std::cout << board_height << std::endl;
    CloseWindow();
    return 0;
}
