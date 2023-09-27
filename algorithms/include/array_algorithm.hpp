#pragma once

#include "./array.hpp"

namespace Algorithms {
    class ArrayAlgorithm {
    protected:
        Array& arr;
        bool finished;

        int ArraySize() const;

    public:
        ArrayAlgorithm(Array& a);

        virtual bool IsDone() const;
        virtual void Reset();

        virtual void Step() = 0;
        virtual void Prepare() = 0;
    };
}

