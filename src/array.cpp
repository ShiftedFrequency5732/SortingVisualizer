#include "../include/array.hpp"
#include <cmath>

Array::Array() {
    for (int i = 0; i < N_ELEMENTS; ++i) {
        // Set default values to all the elements.
        vector[i].SetValue(i + 1);
    }
}

Element& Array::operator[] (int i) {
    return this->vector[i];
}

void Array::Draw() {
    int x_offset = 0;

    for (int i = 0; i < N_ELEMENTS; ++i) {
        // Calculate the height of each element, based on its height, the height will be equal to the % of the window height.
        int element_heigth = (1.0 * GetRenderHeight() * vector[i].GetValue() / N_ELEMENTS);

        // Calculate the width of each element, based on the window width.
        int element_width = 1.0 * GetRenderWidth() / N_ELEMENTS;

        // If there was remainder when dividing the width with N, then if we render the elements like that we would have an empty part of the window on the right.
        // To fill that in, the remainder number of elements need to have its width increased by one pixel.
        bool increase_width = i < GetRenderWidth() % N_ELEMENTS;

        // Draw the element the i-th slice of the window, at the height of the element from the bottom of the screen of calculated size, with its current color.
        DrawRectangle(i * element_width + x_offset, GetRenderHeight() - element_heigth, element_width + (int)increase_width, element_heigth, vector[i].GetFillColor());

        if (increase_width) {
            // In case we have increased the width of the current element by 1 pixel, we will have to offset the rest of the elements by one extra pixel on the x axis.
            ++x_offset;
        }

        // Reset the color of the element to white in case it was changed.
        if (vector[i].ShouldResetFill()) {
            vector[i].ResetFill();
        }
    }
}
