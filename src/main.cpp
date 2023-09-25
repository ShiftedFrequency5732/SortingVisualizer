#include "../include/config.hpp"
#include "../include/array.hpp"

#include "../include/fisher_yates_shuffle.hpp"

#include "../include/raylib.h"
#include "../include/raymath.h"

int main() {
    // Initialize the window with the width, the height, the title, set the target FPS, make it resizable.
    InitWindow(INITIAL_WIDTH, INITIAL_HEIGHT, WINDOW_TITLE);
    SetTargetFPS(GetMonitorRefreshRate(GetCurrentMonitor()));
    SetWindowState(FLAG_WINDOW_RESIZABLE);

    // Create array object.
    Array arr;

    // Algorithms that can be used.
    FisherYatesShuffle f(arr);

    // Pointer that points to the picked algorith, and flag that indicates whether to run the algorithm or not.
    Algorithm* array_adjust = &f;
    bool run_algorithm = false;

    while (!WindowShouldClose()) {
        BeginDrawing();

        // Clear the window from previous loop.
        ClearBackground(BLANK);

        arr.Draw();

        if (run_algorithm) {
            if (array_adjust->Step()) {
                // If the algorithm reached the end stop.
                run_algorithm = false;
            }
        }

        if (!run_algorithm && IsKeyPressed(KEY_SPACE)) {
            // In case the user pressed space, prepare the algorithm, and start running it in the next loop iteration.
            array_adjust->Prepare();
            run_algorithm = true;
        }

        EndDrawing();
    }

    return 0;
}

