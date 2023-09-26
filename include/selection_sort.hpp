#pragma once

#include "./algorithm.hpp"

class SelectionSort : public Algorithm {
private:
    int i, min_i, j;
    bool j_round_done;

public:
    using Algorithm::Algorithm;

    void Step();
    void Prepare();
};

