#include "../include/merge_sort.hpp"

void MergeSort::Prepare() {
    this->partition_size = 1;
    this->left = 0;
    this->end_left = false;
    this->merge_done = false;
    this->coppied = false;
}

void MergeSort::Merge(int left, int mid, int right) {
    if (!this->coppied) {
        this->left_length = mid - left + 1;
        this->right_length = right - (mid + 1) + 1;

        for (int i = 0; i < this->left_length; ++i) {
            this->temp_left[i] = this->arr[left + i].GetValue();
        }
        for (int i = 0; i < this->right_length; ++i) {
            this->temp_right[i] = this->arr[mid + 1 + i].GetValue();
        }


        this->a = 0;
        this->b = 0;
        this->free = left;
        this->coppied = true;
    }

    if (a < left_length && b < right_length) {
        if (temp_left[a] < temp_right[b]) {
            this->arr[free].SetValue(temp_left[a]);
            this->arr[free].SetFillColor(RED);
            ++a;
        }
        else {
            this->arr[free].SetValue(temp_right[b]);
            this->arr[free].SetFillColor(RED);
            ++b;
        }
        ++free;
    }
    else {
        if (a < left_length) {
            this->arr[free].SetValue(temp_left[a]);
            this->arr[free].SetFillColor(RED);
            ++free;
            ++a;
        }
        else if (b < right_length) {
            this->arr[free].SetValue(temp_right[b]);
            this->arr[free].SetFillColor(RED);
            ++free;
            ++b;
        }
        else {
            this->merge_done = true;
        }
    }
}

void MergeSort::Step() {
    if (partition_size <= N_ELEMENTS - 1) {
        if (this->end_left) {
            this->left = 0;
            this->end_left = false;
            partition_size = 2 * partition_size;
        }

        if (left < N_ELEMENTS - 1) {
            int mid = std::min(left + partition_size - 1, N_ELEMENTS - 1);
            int right = std::min(left + 2 * partition_size - 1, N_ELEMENTS - 1);

            this->Merge(left, mid, right);

            if (this->merge_done) {
                left = left + 2 * partition_size;
                this->merge_done = false;
                this->coppied = false;
            }
        }
        else {
            this->end_left = true;
        }

        return;
    }

    this->finished = true;
}
