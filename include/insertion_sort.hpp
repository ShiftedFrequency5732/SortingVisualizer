#pragma once

#include "./algorithm.hpp"

class InsertionSort : public Algorithm {
private:
    int i, j;
    Element temp;

public:
    using Algorithm::Algorithm;

    void Step();
    void Prepare();
};

