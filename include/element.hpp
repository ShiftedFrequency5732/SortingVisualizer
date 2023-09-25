#pragma once

#include "./raylib.h"

class Element {
private:
    int value;
    Color fill;

public: 
    Element(int value = 0);

    void setValue(int value);
    int getValue() const;

    void setFillColor(Color fill);
    Color getFillColor() const;

    friend bool operator < (const Element& e1, const Element& e2);
};

