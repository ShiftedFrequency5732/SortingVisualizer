#pragma once

#include "./array_algorithm.hpp"

namespace Algorithms {
    class BubbleSort : public ArrayAlgorithm {
    private:
        int i, j;

    public:
        using ArrayAlgorithm::ArrayAlgorithm;

        void Step();
        void Prepare();
    };
}

