
#include "../include/selection_sort.hpp"

void SelectionSort::Prepare() {
    // At the start, we will look for the smallest element for position 0.
    this->i = 0;

    // Auxiliary fields for the selection sort.
    this->j = 0;
    this->min_i = 0;
    this->j_end = true;
}

void SelectionSort::Step() {
    if (this->i < N_ELEMENTS - 1) {
        if (this->j_end) {
            // In case we have previously reached the end with j, then start looking for the smallest element again.
            this->j_end = false;
            this->min_i = this->i;
            this->j = this->min_i + 1;
        }

        if (j < N_ELEMENTS) {
            if (this->arr[j] < this->arr[this->min_i]) {
                // If you have found the smaller element than at the min_i, remember it.
                this->min_i = j;
            }
            // Color the element you are currently at with red, and increment the j.
            this->arr[j++].setFillColor(RED);
        }

        if (j >= N_ELEMENTS) {
            if (this->i != this->min_i) {
                // If we reached the end and looked for all the elements to the right of min_i, then check if we have found smaller element then min_i.
                // If we did, swap the element at the i with element at min_i.
                Element temp = this->arr[this->i];
                this->arr[this->i] = this->arr[this->min_i];
                this->arr[this->min_i] = temp;
            }

            // If we didn't find anything smaller, then this element for this position is already smallest one.
            j_end = true;
            ++this->i;
        }

        return;
    }

    // If we went through all the rounds, set that we finished sorting to true.
    this->finished = true;
}
