#include "../include/config.hpp"
#include "../include/array.hpp"

#include "../include/fisher_yates_shuffle.hpp"
#include "../include/bogo_sort.hpp"
#include "../include/counting_sort.hpp"
#include "../include/bubble_sort.hpp"
#include "../include/selection_sort.hpp"
#include "../include/insertion_sort.hpp"
#include "../include/merge_sort.hpp"
#include "../include/quick_sort.hpp"

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
    InsertionSort insertion_alg(data);
    CountingSort counting_alg(data);
    BogoSort bogo_alg(data);
    MergeSort merge_alg(data);
    QuickSort quick_alg(data);

    // Pointer that points to the picked algorithm, and flag that indicates whether to run the algorithm or not.
    Algorithm* sorting_algorithm = &bubble_alg;
    bool run_algorithm = false;

    while (!WindowShouldClose()) {
        // Prepare new frame buffer. Clear the window from previous loop. Draw the array.
        BeginDrawing();
        ClearBackground(BLANK);
        data.Draw();

        if (run_algorithm) {
            if (!shuffler.IsDone()) {
                // Shuffle the array first before running the actual sorting algorithm.
                shuffler.Step();
            }
            else if (!sorting_algorithm->IsDone()) {
                // After shuffling the array, sort it using the picked algortihm.
                sorting_algorithm->Step();
            }
            else {
                // After sorting the array, stop running the algorithms.
                run_algorithm = false;
            }
        }

        // Pick an algorithm.
        if (!run_algorithm && IsKeyPressed(KEY_ONE)) {
            sorting_algorithm = &bogo_alg;
        }
        else if (!run_algorithm && IsKeyPressed(KEY_TWO)) {
            sorting_algorithm = &counting_alg;
        }
        else if (!run_algorithm && IsKeyPressed(KEY_THREE)) {
            sorting_algorithm = &bubble_alg;
        }
        else if (!run_algorithm && IsKeyPressed(KEY_FOUR)) {
            sorting_algorithm = &selection_alg;
        }
        else if (!run_algorithm && IsKeyPressed(KEY_FIVE)) {
            sorting_algorithm = &insertion_alg;
        }
        else if (!run_algorithm && IsKeyPressed(KEY_SIX)) {
            sorting_algorithm = &merge_alg;
        }
        else if (!run_algorithm && IsKeyPressed(KEY_SEVEN)) {
            sorting_algorithm = &quick_alg;
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

