#include "../include/fisher_yates_shuffle.hpp"

void FisherYatesShuffle::Prepare() {
    this->iter = N_ELEMENTS - 1;
    this->finished = false;
}

void FisherYatesShuffle::Step() {
    if (iter >= 0) {
        int new_index = GetRandomValue(0, this->iter);

        Element temp = this->arr[iter];
        this->arr[iter] = this->arr[new_index];
        this->arr[new_index] = temp;
        this->arr[iter].setFillColor(RED);

        --this->iter;
        return;
    }

    this->finished = true;
}

