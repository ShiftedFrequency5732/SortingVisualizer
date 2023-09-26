#include "../include/raylib.h"
#include "../include/raymath.h"

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

int main() {
    // Initialize the window with the width, the height, the title, set the target FPS, make it resizable.
    InitWindow(INITIAL_WIDTH, INITIAL_HEIGHT, WINDOW_TITLE);
    SetTargetFPS(GetMonitorRefreshRate(GetCurrentMonitor()));
    SetWindowState(FLAG_WINDOW_RESIZABLE);

    Array data;
    FisherYatesShuffle shuffler(data);

    // Algorithms that can be used.
    BogoSort bogo_alg(data);
    CountingSort counting_alg(data);
    BubbleSort bubble_alg(data);
    SelectionSort selection_alg(data);
    InsertionSort insertion_alg(data);
    MergeSort merge_alg(data);
    QuickSort quick_alg(data);

    // Pointer that points to the picked algorithm, and flag that indicates whether to run the algorithm or not.
    Algorithm* sorting_algorithm = &bogo_alg;
    bool run_algorithm = false;

    // Flag that indicates whether to show help text or not.
    bool show_help = true;

    while (!WindowShouldClose()) {
        // Prepare new frame buffer. Clear the window from previous loop. Draw the array.
        BeginDrawing();
        ClearBackground(BLANK);
        data.Draw();

        if (show_help) {
            // Draw the help box on the center of the screen, based on the text size.
            Vector2 txt_size = MeasureTextEx(GetFontDefault(), HELP_TEXT, FONT_SIZE, SPACING);
            DrawRectangle(GetRenderWidth() / 2 - txt_size.x / 2 - BG_MARGIN / 2, GetRenderHeight() / 2 - txt_size.y / 2 - BG_MARGIN / 2, txt_size.x + BG_MARGIN, txt_size.y + BG_MARGIN, LIGHTGRAY);
            DrawTextEx(GetFontDefault(), HELP_TEXT, { GetRenderWidth() / 2 - txt_size.x / 2, GetRenderHeight() / 2 - txt_size.y / 2 }, FONT_SIZE, SPACING, BLACK);
        }

        EndDrawing();

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

        if ((IsKeyDown(KEY_LEFT_SHIFT) || IsKeyDown(KEY_RIGHT_SHIFT)) && IsKeyPressed(KEY_SLASH)) {
            // In case the question mark has been pressed toggle the help.
            show_help = !show_help;
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
            show_help = false;
        }

        if (!run_algorithm) {
            float scroll_value = GetMouseWheelMove();
            data.SetVisible(data.GetVisible() + scroll_value);
        }
    }

    return 0;
}

