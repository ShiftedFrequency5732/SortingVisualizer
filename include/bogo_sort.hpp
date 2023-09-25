#pragma once

#include "./algorithm.hpp"

class BogoSort : public Algorithm {
private:
    int i, j;

public:
    using Algorithm::Algorithm;

    void Step(); 
    void Prepare();
};

