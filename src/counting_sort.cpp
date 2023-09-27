#include "../include/counting_sort.hpp"

void CountingSort::Prepare() {
    // At the start, every element appears exactly zero times.
    for (int i = 0; i < this->ArraySize() + 1; ++i) {
        this->histogram[i] = 0;
    }

    // We will go from the 1st element of the array up to the end.
    this->i = 0;

    // The first free slot of the array is zero.
    this->free = 0;

    // The k-th number that we will look at in the histogram at the start is zero.
    this->k = 0;
}

void CountingSort::Step() {
    if (this->i < this->ArraySize()) {
        // Increment the number of appearances of the current element, make it red, and move on to the next one.
        ++this->histogram[this->arr[this->i].GetValue()];
        this->arr[this->i].SetFocus(RED);
        ++this->i;
        return;
    }

    if (this->free < this->ArraySize()) {
        while (this->histogram[this->k] == 0) {
            // As long as the current element appears zero times, find one that appears > 0 times.
            ++this->k;
        }

        // At the free slot in the array, store the current k-th element (number), make it blue without reseting color.
        this->arr[this->free].SetValue(this->k);
        this->arr[this->free].SetFocus(BLUE, false);

        // Decrement the number of times the number k appears in the histogram.
        --this->histogram[this->k];

        // Move on to the next free slot of the array.
        ++this->free;
        return;
    }

    // If we completed the counting sort algorithm, set that we are done.
    this->finished = true;
}
