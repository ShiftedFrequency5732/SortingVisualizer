#include "../include/config.hpp"

#include "../include/raylib.h"
#include "../include/raymath.h"

int main() {
    // Initialize the window with the width, the height, the title, set the target FPS, make it resizable.
    InitWindow(INITIAL_WIDTH, INITIAL_HEIGHT, WINDOW_TITLE);
    SetTargetFPS(GetMonitorRefreshRate(GetCurrentMonitor()));
    SetWindowState(FLAG_WINDOW_RESIZABLE);

    while (!WindowShouldClose()) {
        BeginDrawing();

        // Clear the window from previous loop.
        ClearBackground(BLANK);

        EndDrawing();
    }

    return 0;
}

