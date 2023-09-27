#pragma once

#include "./raylib.h"

class Element {
private:
    int value;
    static int max_value;

    Color default_fill;
    Color current_fill;
    bool reset_fill;

public:
    Element(int value = 0, Color fill = WHITE);

    static void SetMaxValue(int max_value);

    void SetValue(int value);
    int GetValue() const;

    void SetFocus(Color fill, bool reset_fill = true);
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

