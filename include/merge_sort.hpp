#pragma once

#include <stack>

#include "./algorithm.hpp"

class MergeSort : public Algorithm {
private:
    int partition_size;
    int left;
    bool end_left;

    bool coppied;
    bool merge_done;

    int left_length, a;
    int temp_left[N_ELEMENTS];

    int right_length, b;
    int temp_right[N_ELEMENTS];

    int free;

    void Merge(int left, int mid, int right);

public:
    using Algorithm::Algorithm;

    void Prepare();
    void Step();
};
