#pragma once

#include "./array_algorithm.hpp"

namespace Algorithms {
    class BogoSort : public ArrayAlgorithm {
    private:
        int i_shuffle, j_check;

    public:
        using ArrayAlgorithm::ArrayAlgorithm;

        void Step();
        void Prepare();
    };
}

