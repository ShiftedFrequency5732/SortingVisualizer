#include "../include/element.hpp"

Element::Element(int value) {
    this->value = value;
    this->fill = WHITE;
}

void Element::setValue(int value) {
    this->value = value;
}

int Element::getValue() const {
    return this->value;
}

void Element::setFillColor(Color fill) {
    this->fill = fill;
}

Color Element::getFillColor() const {
    return this->fill;
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

