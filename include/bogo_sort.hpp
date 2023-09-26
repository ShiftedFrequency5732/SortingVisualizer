#pragma once

#include "./algorithm.hpp"

class BogoSort : public Algorithm {
private:
    int i_shuffle, j_check;

public:
    using Algorithm::Algorithm;

    void Step();
    void Prepare();
};

