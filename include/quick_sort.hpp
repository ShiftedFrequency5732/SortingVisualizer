#pragma once

#include <stack>
#include "./algorithm.hpp"

class QuickSort : public Algorithm {
private:
    std::stack<std::pair<int, int>> ranges;
    int low, high;

    int left, right;
    bool valid_ptrs;
    bool left_checked;
    bool right_checked;

    Element pivot;
    int pivot_index;
    bool pivot_set;

    bool done_partitioning;

    void Partition();

public:
    using Algorithm::Algorithm;

    void Prepare();
    void Step();
};

