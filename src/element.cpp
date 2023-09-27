#include "../include/element.hpp"
#include "../include/config.hpp"
#include "../include/tone_generator.hpp"

int Element::max_value = Constants::N_ELEMENTS / 4;

Element::Element(int value, Color fill) {
    this->value = value;
    this->default_fill = this->current_fill = fill;
}

void Element::SetMaxValue(int max_value) {
    Element::max_value = max_value;
}

void Element::SetValue(int value) {
    this->value = value;
}

int Element::GetValue() const {
    return this->value;
}

void Element::SetFocus(Color fill, bool reset_fill) {
    this->current_fill = fill;
    this->reset_fill = reset_fill;

    // Set the frequency of the tone generator based on the value of the current element.
    // We will take the current value and divide with the maximum value so we get the % and multiply that with the MAX_FREQUENCY.
    ToneGenerator::SetFrequency(1.0f * this->value / Element::max_value * Constants::MAX_FREQUENCY);
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

