#pragma once

#include "./algorithm.hpp"

class FisherYatesShuffle : public Algorithm {
private:
    int iter;

public:
    using Algorithm::Algorithm;

    bool Step(); 
    void Prepare();
};
