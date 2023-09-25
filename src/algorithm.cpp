#include "../include/algorithm.hpp"

Algorithm::Algorithm(Array& a) : arr(a) {
    this->finished = false;
}

bool Algorithm::IsDone() {
    return this->finished;
}

void Algorithm::Reset() {
    this->finished = false;
    this->Prepare();
}

