#include "../include/array.hpp"

Array::Array() {
    for (int i = 0; i < N_ELEMENTS; ++i) {
        vector[i].setValue(i + 1);
    }
}

void Array::Draw() {
    int element_width = (1.0 * GetRenderWidth() / N_ELEMENTS);

    for (int i = 0; i < N_ELEMENTS; ++i) {
        int element_heigth = GetRenderHeight() * vector[i].getValue() / N_ELEMENTS;
        DrawRectangle(i * element_width, GetRenderHeight() - element_heigth, element_width, element_heigth, vector[i].getFillColor());
    }
}
