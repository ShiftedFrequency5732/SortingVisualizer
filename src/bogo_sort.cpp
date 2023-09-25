#include "../include/bogo_sort.hpp"

void BogoSort::Prepare() {
    // Set the iterator to be at the end.
    this->i = N_ELEMENTS - 1;
    this->j = 0;
}

void BogoSort::Step() {
    if (i >= 1) {
        // For each element, (except the first one), that has index i, generate a new index in range [0, i].
        // We won't do this for the first element, as that element will always get the newly generated index to be 0.
        int new_index = GetRandomValue(0, this->i);

        // Swap the elements at the current index i and newly generated indeces..
        Element temp = this->arr[i];
        this->arr[i] = this->arr[new_index];
        this->arr[new_index] = temp;

        // Color the elements RED.
        this->arr[i].setFillColor(RED);
        this->arr[new_index].setFillColor(RED);

        --this->i;
        return;
    }
    else if (this->j < N_ELEMENTS - 1) {
        // Color the two elements that we will compare with red.
        this->arr[j].setFillColor(RED);
        this->arr[j + 1].setFillColor(RED);

        if (this->arr[j] > this->arr[j + 1]) {
            // If the elements aren't sorted, start over with shuffling.
            this->i = N_ELEMENTS - 1;
            this->j = 0;
        }
        else {
            ++this->j;
        }

        return;
    }

    // If we did this for all the elements, we finished.
    this->finished = true;
}

