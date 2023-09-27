#pragma once

#include "./config.hpp"
#include "./element.hpp"

class Array {
private:
    Element vector[Constants::N_ELEMENTS];
    int visible;

public:
    Array();

    void SetVisible(int visible_elements);
    int GetVisible() const;

    Element& operator[] (int i);

    void Draw();
};

