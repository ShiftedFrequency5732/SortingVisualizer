#include "../include/config.hpp"

#include "../include/array.hpp"
#include "../include/fisher_yates_shuffle.hpp"
#include "../include/bubble_sort.hpp"
#include "../include/selection_sort.hpp"

#include "../include/raylib.h"
#include "../include/raymath.h"

int main() {
    // Initialize the window with the width, the height, the title, set the target FPS, make it resizable.
    InitWindow(INITIAL_WIDTH, INITIAL_HEIGHT, WINDOW_TITLE);
    SetTargetFPS(GetMonitorRefreshRate(GetCurrentMonitor()));
    SetWindowState(FLAG_WINDOW_RESIZABLE);

    Array data;
    FisherYatesShuffle shuffler(data);

    // Algorithms that can be used.
    BubbleSort bubble_alg(data);
    SelectionSort selection_alg(data);

    // Pointer that points to the picked algorith, and flag that indicates whether to run the algorithm or not.
    Algorithm* sorting_algorithm = &bubble_alg;
    bool run_algorithm = false;

    while (!WindowShouldClose()) {
        BeginDrawing();

        // Clear the window from previous loop, draw the array.
        ClearBackground(BLANK);
        data.Draw();

        if (run_algorithm) {
            if (!shuffler.IsDone()) {
                // Shuffle the array first.
                shuffler.Step();
            }
            else if (!sorting_algorithm->IsDone()) {
                // After shuffling the array, sort it.
                sorting_algorithm->Step();
            }
            else {
                // After sorting the array, stop running algorithms.
                run_algorithm = false;
            }
        }

        // Pick an algorithm.
        if (!run_algorithm && IsKeyPressed(KEY_ONE)) {
            sorting_algorithm = &bubble_alg;
        }
        else if (!run_algorithm && IsKeyPressed(KEY_TWO)) {
            sorting_algorithm = &selection_alg;
        }

        if (IsKeyPressed(KEY_SPACE)) {
            // Prepare shuffler and the sorting algorithm, toggle the run flag.
            shuffler.Reset();
            sorting_algorithm->Reset();
            run_algorithm = !run_algorithm;
        }

        EndDrawing();
    }

    return 0;
}

