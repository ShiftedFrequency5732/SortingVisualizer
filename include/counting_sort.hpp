#pragma once

#include "./config.hpp"
#include "./algorithm.hpp"

class CountingSort : public Algorithm {
private:
    int histogram[Constants::N_ELEMENTS + 1];
    int i, free, k;

public:
    using Algorithm::Algorithm;

    void Step();
    void Prepare();
};

