#pragma once

#include "./array.hpp"

class Algorithm {
protected:
    Array& arr;
    bool finished;

    int ArraySize() const;

public:
    Algorithm(Array& a);

    virtual bool IsDone();
    virtual void Reset();

    virtual void Step() = 0;
    virtual void Prepare() = 0;
};

