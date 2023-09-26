#pragma once

#include "./algorithm.hpp"

class InsertionSort : public Algorithm {
private:
    int i, j;
    bool j_round_done;
    Element temp;

public:
    using Algorithm::Algorithm;

    void Step();
    void Prepare();
};

