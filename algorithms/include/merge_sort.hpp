#pragma once

#include "./array_algorithm.hpp"

namespace Algorithms {
    class MergeSort : public ArrayAlgorithm {
    private:
        int partition_size;
        int low;

        bool coppied;
        bool merge_done;

        int left_len, a;
        int left_tmp[Constants::N_ELEMENTS];

        int right_len, b;
        int right_tmp[Constants::N_ELEMENTS];

        int free;

        void Merge(int low, int mid, int high);

    public:
        using ArrayAlgorithm::ArrayAlgorithm;

        void Prepare();
        void Step();
    };
}

