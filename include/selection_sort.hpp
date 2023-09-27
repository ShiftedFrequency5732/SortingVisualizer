#pragma once

#include "./algorithm.hpp"

class SelectionSort : public Algorithm {
private:
    int i, min_i, j;

public:
    using Algorithm::Algorithm;

    void Step();
    void Prepare();
};

