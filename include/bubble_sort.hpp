#pragma once

#include "./algorithm.hpp"

class BubbleSort : public Algorithm {
private:
    int i, j;
    bool change;

public:
    using Algorithm::Algorithm;

    void Step();
    void Prepare();
};
