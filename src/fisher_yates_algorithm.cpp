#include "../include/fisher_yates_shuffle.hpp"

void FisherYatesShuffle::Prepare() {
    // Set the iterator to be at the last element.
    this->i = this->ArraySize() - 1;
}

void FisherYatesShuffle::Step() {
    if (i >= 1) {
        // For each element, (except the first one), that has index i, generate a new index in the range [0, i].
        // We won't do this for the first element, as that element will always get the newly generated index to be 0.
        int new_index = GetRandomValue(0, this->i);

        // Swap the elements at the current index i and newly generated index
        Element temp = this->arr[i];
        this->arr[i] = this->arr[new_index];
        this->arr[new_index] = temp;

        // Color the elements RED, to visualize the process.
        this->arr[i].SetFillColor(RED);
        this->arr[new_index].SetFillColor(RED);

        // Move backwards to the previous elements.
        --this->i;
        return;
    }

    // If we did this for all the elements, we finished.
    this->finished = true;
}

