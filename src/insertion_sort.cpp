#include "../include/insertion_sort.hpp"

void InsertionSort::Prepare() {
    // At the start, we will start from the 2nd element.
    this->i = 1;
    this->j = 0;

    // Auxiliary variables for the insertion sort.
    this->j_round_done = true;
}

void InsertionSort::Step() {
    if (this->i < N_ELEMENTS) {
        if (this->j_round_done) {
            // If we did reach in the previous round the start and found the first smaller element than i-th element.
            // Then we will again, remember the current element at the position i, and try to find the smaller element than it to the left.
            this->temp = this->arr[i];
            this->j = this->i - 1;
            this->j_round_done = false;
        }

        if (this->j >= 0 && this->arr[this->j] > this->temp) {
            // If the j-th element is greater than temp, copy it to the following position, make it red.
            this->arr[this->j + 1] = this->arr[this->j];
            if (this->i < N_ELEMENTS - 1) {
                this->arr[this->j + 1].SetFillColor(RED);
            }
            --j;
        }
        else {
            // If you found the first smaller element, store the temp next to it.
            this->arr[this->j + 1] = this->temp;
            this->j_round_done = true;
            ++this->i;
        }

        return;
    }

    // If we went through all the rounds, set that we finished sorting to true.
    this->finished = true;
}

