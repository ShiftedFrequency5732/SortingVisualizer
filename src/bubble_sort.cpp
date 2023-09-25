#include "../include/bubble_sort.hpp"

void BubbleSort::Prepare() {
    // At start there wasn't any change, initialize the pointers to point to the 0th elements.
    this->change = false;
    this->i = 0;
    this->j = 0;
}

void BubbleSort::Step() {
    if (this->i < N_ELEMENTS - 1) {
        if (this->j < N_ELEMENTS - 1 - i) {
            // When comparing two elements, set their color to red.
            this->arr[j].setFillColor(RED);
            this->arr[j + 1].setFillColor(RED);

            if (this->arr[j] > this->arr[j + 1]) {
                // If you found two elements in the wrong order, swap them.
                Element temp = this->arr[j];
                this->arr[j] = this->arr[j + 1];
                this->arr[j + 1] = temp;
                change = true;
            }

            // Move to the next element.
            ++this->j;

            if (this->j >= N_ELEMENTS - 1 - i) {
                // If we finished one round of the bubble sort, move onto the next.
                this->j = 0;
                ++this->i;

                if (!change) {
                    // In case we didn't find any change in the last round, that means the array is already sorted.
                    this->finished = true;
                }

                // If there was a change, start tracking for the changes again for the following round.
                change = false;
            }
        }

        return;
    }

    // If we went through all the rounds, set that we finished sorting to true.
    this->finished = true;
}
