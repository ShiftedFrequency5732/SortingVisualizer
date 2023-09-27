#pragma once

#include "./array_algorithm.hpp"

namespace Algorithms {
    class SelectionSort : public ArrayAlgorithm {
    private:
        int i, min_i, j;

    public:
        using ArrayAlgorithm::ArrayAlgorithm;

        void Step();
        void Prepare();
    };
}
