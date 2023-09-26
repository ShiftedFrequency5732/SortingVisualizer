#include "../include/quick_sort.hpp"
#include <iostream>

void QuickSort::Prepare() {
    this->ranges = std::stack<std::pair<int, int>>();
    this->ranges.push({ 0, N_ELEMENTS - 1 });
    this->done_partitioning = true;
    this->have_pivot = false;
    this->done_left = false;
    this->done_right = false;
}

void QuickSort::Partition() {
    if (this->have_pivot == false)  {
        this->pivot = this->arr[this->low];
        this->have_pivot = true;

        this->curr_left = this->low;
        this->curr_right = this->high;

        this->done_left = false;
        this->done_right = false;
        this->confirmed = false;
        return;
    }

    if (this->curr_left < this->curr_right) {
        this->confirmed = true;
    }

    if (this->confirmed) {
        if (!this->done_left) {
            if (this->arr[curr_left] <= pivot && curr_left < curr_right) {
                this->arr[curr_left].setFillColor(RED);
                ++this->curr_left;
            }
            else {
                this->done_left = true;
            }
            return;
        }

        if (!this->done_right) {
            if (this->arr[curr_right] > pivot) {
                this->arr[curr_right].setFillColor(RED);
                --this->curr_right;
            }
            else {
                this->done_right = true;
            }
            return;
        }

        if (this->curr_left < this->curr_right) {
            this->done_left = false;
            this->done_right = false;

            Element temp = this->arr[this->curr_left];
            this->arr[this->curr_left] = this->arr[this->curr_right];
            this->arr[this->curr_right] = temp;

            this->arr[this->curr_left].setFillColor(RED);
            this->arr[this->curr_right].setFillColor(RED);
            if (this->curr_left > this->curr_right) {
                this->confirmed = false;
            }
            return;
        }
    }

    this->arr[low] = this->arr[curr_right];
    this->arr[curr_right] = pivot;
    pivot_index = curr_right;

    this->arr[curr_right].setFillColor(RED);
    this->arr[low].setFillColor(RED);

    this->done_partitioning = true;
}

void QuickSort::Step() {
    if (this->done_partitioning && !ranges.empty()) {
        std::pair<int, int> r = ranges.top();
        ranges.pop();

        low = r.first;
        high = r.second;

        if (low >= high) {
            return;
        }

        this->done_partitioning = false;
        this->have_pivot = false;
    }
    else if (this->done_partitioning && ranges.empty()) {
        finished = true;
        return;
    }

    if (low < high) {
        this->Partition();
        if (this->done_partitioning) {
            if ((pivot_index - low) <= (high - pivot_index)) {
                ranges.push({ low, pivot_index - 1 });
                ranges.push({ pivot_index + 1, high});
            }
            else {
                ranges.push({ pivot_index + 1, high});
                ranges.push({ low, pivot_index - 1 });
            }
        }
    }
}

