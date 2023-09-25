#pragma once

#include "./algorithm.hpp"

class BubbleSort : public Algorithm {
private:
    int i, j;
public:
    using Algorithm::Algorithm;

    bool Step();
    void Prepare();
};
