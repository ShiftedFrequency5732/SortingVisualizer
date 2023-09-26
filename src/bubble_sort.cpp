#include "../include/bubble_sort.hpp"

void BubbleSort::Prepare() {
    // Initialize the pointers to point to the first elements.
    this->i = 0;
    this->j = 0;
}

void BubbleSort::Step() {
    if (this->i < this->ArraySize() - 1) {
        if (this->j < this->ArraySize() - 1 - i) {
            // When comparing two elements, set their color to red.
            this->arr[j].SetFillColor(RED);
            this->arr[j + 1].SetFillColor(RED);

            if (this->arr[j] > this->arr[j + 1]) {
                // If you found the two elements that are in the wrong order, swap them.
                // Remember that there was a change (a swap).
                Element temp = this->arr[j];
                this->arr[j] = this->arr[j + 1];
                this->arr[j + 1] = temp;
            }

            // Move to the next element.
            ++this->j;

            if (this->j >= this->ArraySize() - 1 - i) {
                // If we finished one round of the bubble sort, move onto the next.
                // Color the newly sorted element with blue, and do not reset its color to default.
                this->arr[this->ArraySize() - 1 - i].SetFillColor(BLUE, false);
                this->j = 0;
                ++this->i;
            }
        }

        return;
    }

    // If we have sorted n - 1 elements, we have sorted all the n elements.
    // Therefore the algorithm above won't color the first element blue, so we will do it manually here.
    this->arr[0].SetFillColor(BLUE, false);

    // If we went through all the rounds, set that we finished sorting to true.
    this->finished = true;
}
