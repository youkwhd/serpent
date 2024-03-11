#pragma once

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 440

#define BLOCK_WIDTH 20
#define BLOCK_HEIGHT 20

#define MAX_X (WINDOW_WIDTH / BLOCK_WIDTH)
#define MAX_Y (WINDOW_HEIGHT / BLOCK_HEIGHT)

#define MOD(a, b) ((((a) % (b)) + (b)) % (b))
