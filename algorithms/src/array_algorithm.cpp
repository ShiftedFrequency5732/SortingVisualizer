#include "../include/array_algorithm.hpp"

namespace Algorithms {
    ArrayAlgorithm::ArrayAlgorithm(Array& a) : arr(a) {
        // At the start, we are not done obviously.
        this->finished = false;
    }

    int ArrayAlgorithm::ArraySize() const {
        return this->arr.GetVisible();
    }

    bool ArrayAlgorithm::IsDone() const {
        return this->finished;
    }

    void ArrayAlgorithm::Reset() {
        // Set that we are not done, and prepare the algorithm.
        this->finished = false;
        this->Prepare();
    }
}

