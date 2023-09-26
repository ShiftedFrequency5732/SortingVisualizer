#pragma once

#include "./algorithm.hpp"

class FisherYatesShuffle : public Algorithm {
private:
    int i;

public:
    using Algorithm::Algorithm;

    void Step();
    void Prepare();
};

