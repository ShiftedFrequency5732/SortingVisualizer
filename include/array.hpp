#pragma once

#include "./config.hpp"
#include "./element.hpp"

class Array {
private:
    Element vector[N_ELEMENTS];

public:
    Array();

    void Draw();
};
