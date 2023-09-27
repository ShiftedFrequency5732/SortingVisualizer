#pragma once

#include "./array_algorithm.hpp"

namespace Algorithms {
    class InsertionSort : public ArrayAlgorithm {
    private:
        int i, j;
        Element temp;

    public:
        using ArrayAlgorithm::ArrayAlgorithm;

        void Step();
        void Prepare();
    };
}

