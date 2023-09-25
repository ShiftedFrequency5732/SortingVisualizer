#include "../include/array.hpp"
#include <cmath>

Array::Array() {
    for (int i = 0; i < N_ELEMENTS; ++i) {
        // Set values to all the elements.
        vector[i].setValue(i + 1);
    }
}

Element& Array::operator [] (int i) {
    return this->vector[i];
}

void Array::Draw() {
    // Calculate the width of each element, based on the window width.
    int element_width = std::ceil(1.0 * GetRenderWidth() / N_ELEMENTS);

    for (int i = 0; i < N_ELEMENTS; ++i) {
        // Calculate the height of each element, based on its height, the height will be equal to the % of the window height.
        int element_heigth = GetRenderHeight() * vector[i].getValue() / N_ELEMENTS;

        // Draw the element the i-th slice of the window, at the height of the element from the bottom of the screen of calculated size, with its current color.
        DrawRectangle(i * element_width, GetRenderHeight() - element_heigth, element_width, element_heigth, vector[i].getFillColor());

        // Reset the color of the element to white in case it was changed.
        vector[i].setFillColor(WHITE);
    }
}
