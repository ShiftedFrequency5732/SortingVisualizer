#include "../include/insertion_sort.hpp"

namespace Algorithms {
    void InsertionSort::Prepare() {
        // At the start, we will start from the 2nd element.
        this->i = 1;
        this->j = 0;
    }

    void InsertionSort::Step() {
        if (this->i < this->ArraySize()) {
            if (this->j >= 0 && this->arr[this->j] > this->temp) {
                // If the j-th element is greater than temp, copy it to the following position, make it red.
                this->arr[this->j + 1] = this->arr[this->j];
                this->arr[this->j + 1].SetFocus(RED);
                --j;
            }
            else {
                // If you found the first smaller element, store the temp next to it.
                this->arr[this->j + 1] = this->temp;

                // Move to the next element.
                this->j = ++this->i - 1;
                this->temp = this->arr[i];
            }

            return;
        }

        // If we went through all the rounds, set that we finished sorting to true.
        this->finished = true;
    }
}

