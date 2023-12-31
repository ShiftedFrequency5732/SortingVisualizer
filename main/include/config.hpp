#pragma once

namespace Constants {
    // Window related constants.
    constexpr int INITIAL_WIDTH = 800;
    constexpr int INITIAL_HEIGHT = 800;
    constexpr const char* WINDOW_TITLE = "Sorting Visualizer - by JV";

    // Array related constants.
    constexpr int N_ELEMENTS = 250;

    // Help related constants.
    constexpr int SPACING = 1;
    constexpr int FONT_SIZE = 40;
    constexpr int BG_MARGIN = 20;
    constexpr const char* HELP_TEXT = "Keyboard Hotkeys:\n1 - Bogo Sort\n2 - Counting Sort\n3 - Bubble Sort\n4 - Selection Sort\n5 - Insertion Sort\n6 - Merge Sort\n7 - Quick Sort\nM - Toggle Audio\nSpace - Run / Stop\n? - Toggle Help\n\nScroll Wheel - Zoom";

    // Audio related constants.
    const int MAX_FREQUENCY = 1000;
    const int AMPLITUDE = 32000;
    const int SAMPLING_RATE = 44100;
    const int SAMPLE_SIZE = 16;
    const int BUFFER_SIZE = 4096;
}

