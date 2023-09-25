#include "../include/bubble_sort.hpp"

void BubbleSort::Prepare() {
    this->i = 0;
    this->j = 0;
    this->finished = false;
}

void BubbleSort::Step() {
    if (this->i < N_ELEMENTS - 1) {
        if (this->j < N_ELEMENTS - 1 - i) {
            if (this->arr[j] > this->arr[j + 1]) {
                this->arr[j].setFillColor(RED);
                this->arr[j + 1].setFillColor(RED);

                Element temp = this->arr[j];
                this->arr[j] = this->arr[j + 1];
                this->arr[j + 1] = temp;
            }
            ++this->j;
        }
        else {
            ++this->i;
            this->j = 0;
        }

        return;
    }
    this->finished = true;
}
