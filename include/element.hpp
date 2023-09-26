#pragma once

#include "./raylib.h"

class Element {
private:
    int value;
    Color default_fill;
    Color current_fill;
    bool reset_fill;

public: 
    Element(int value = 0, Color fill = WHITE);

    void SetValue(int value);
    int GetValue() const;

    void SetFillColor(Color fill, bool reset_fill = true);
    Color GetFillColor() const;

    bool ShouldResetFill() const;
    void ResetFill();

    friend bool operator < (const Element& e1, const Element& e2);
    friend bool operator > (const Element& e1, const Element& e2);

    friend bool operator <= (const Element& e1, const Element& e2);
    friend bool operator >= (const Element& e1, const Element& e2);

    friend bool operator == (const Element& e1, const Element& e2);
    friend bool operator != (const Element& e1, const Element& e2);
};

