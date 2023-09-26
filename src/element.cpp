#include "../include/element.hpp"

Element::Element(int value, Color fill) {
    this->value = value;
    this->default_fill = fill;
    this->current_fill = fill;
}

void Element::SetValue(int value) {
    this->value = value;
}

int Element::GetValue() const {
    return this->value;
}

void Element::SetFillColor(Color fill, bool reset_fill) {
    this->current_fill = fill;
    this->reset_fill = reset_fill;
}

Color Element::GetFillColor() const {
    return this->current_fill;
}

bool Element::ShouldResetFill() const {
    return this->reset_fill;
}

void Element::ResetFill() {
    this->current_fill = this->default_fill;
}

bool operator < (const Element& e1, const Element& e2) {
    return (e1.value < e2.value);
}

bool operator > (const Element& e1, const Element& e2) {
    return (e1.value > e2.value);
}

bool operator <= (const Element& e1, const Element& e2) {
    return (e1.value <= e2.value);
}

bool operator >= (const Element& e1, const Element& e2) {
    return (e1.value >= e2.value);
}

bool operator == (const Element& e1, const Element& e2) {
    return (e1.value == e2.value);
}

bool operator != (const Element& e1, const Element& e2) {
    return (e1.value != e2.value);
}

