#include <iostream>

#include "board.h"

int main(void)
{
    board::Board *board = new board::Board;
    board->__hello("C++");
    delete board;

    return 0;
}
