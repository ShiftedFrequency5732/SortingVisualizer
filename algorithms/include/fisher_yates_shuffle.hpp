#pragma once

#include "./array_algorithm.hpp"

namespace Algorithms {
    class FisherYatesShuffle : public ArrayAlgorithm {
    private:
        int i;

    public:
        using ArrayAlgorithm::ArrayAlgorithm;

        void Step();
        void Prepare();
    };
}

