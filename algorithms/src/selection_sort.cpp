
#include "../include/selection_sort.hpp"

namespace Algorithms {
    void SelectionSort::Prepare() {
        // At the start, we will look for the smallest element for the position 0.
        this->i = 0;
        this->j = 1;
        this->min_i = 0;
    }

    void SelectionSort::Step() {
        if (this->i < this->ArraySize() - 1) {
            if (j < this->ArraySize()) {
                if (this->arr[j] < this->arr[this->min_i]) {
                    // If you have found the smaller element than at the min_i, remember it.
                    this->min_i = j;
                }

                // Color the element you are currently at with red, and increment the j.
                this->arr[j++].SetFocus(RED);
            }
            else {
                if (this->i != this->min_i) {
                    // If we reached the end and looked for all the elements to the right of min_i, then check if we have found the smaller element than the one at min_i.
                    // If we did, swap the element at the i with element at min_i.
                    Element temp = this->arr[this->i];
                    this->arr[this->i] = this->arr[this->min_i];
                    this->arr[this->min_i] = temp;
                }

                // As this is the smallest element for this position, it is final, therefore color the i-th element with blue without reseting the color.
                // If we didn't find anything smaller, then this element for this position is already the smallest one.
                this->arr[this->i].SetFocus(BLUE, false);

                ++this->i;
                this->min_i = this->i;
                this->j = this->min_i + 1;
            }

            return;
        }

        // If we sort n - 1 elements, and we have n elements, then we have sorted all of them.
        // Based on that, the above algorithm won't color the last element to blue, so we will do it manually.
        this->arr[this->ArraySize() - 1].SetFocus(BLUE, false);

        // If we went through all the rounds, set that we finished sorting to true.
        this->finished = true;
    }
}

