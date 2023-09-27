#pragma once

#include "./array_algorithm.hpp"

namespace Algorithms {
    class CountingSort : public ArrayAlgorithm {
    private:
        int histogram[Constants::N_ELEMENTS + 1];
        int i, free, k;

    public:
        using ArrayAlgorithm::ArrayAlgorithm;

        void Step();
        void Prepare();
    };
}

