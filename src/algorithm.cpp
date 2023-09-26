#include "../include/algorithm.hpp"

Algorithm::Algorithm(Array& a) : arr(a) {
    // At the start, we are not done obviously.
    this->finished = false;
}

int Algorithm::ArraySize() const {
    return this->arr.GetVisible();
}

bool Algorithm::IsDone() {
    return this->finished;
}

void Algorithm::Reset() {
    // Set that we are not done, and prepare the algorithm.
    this->finished = false;
    this->Prepare();
}

