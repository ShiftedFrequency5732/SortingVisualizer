#include <algorithm>
#include "../include/merge_sort.hpp"

void MergeSort::Prepare() {
    // At the start, we will work with partitions of size 1 from the left to the right.
    this->partition_size = 1;
    this->low = 0;

    // Auxiliary variables for the merge sort.
    this->merge_done = false;
    this->coppied = false;
}

void MergeSort::Merge(int low, int mid, int high) {
    if (!this->coppied) {
        // Calculate the lengths of both partitions.
        this->left_len = mid - low + 1;
        this->right_len = high - mid;

        // Copy both the left and the right partitions to the temporary arrays.
        for (int i = 0; i < this->left_len; ++i) {
            this->left_tmp[i] = this->arr[low + i].GetValue();
        }
        for (int i = 0; i < this->right_len; ++i) {
            this->right_tmp[i] = this->arr[mid + 1 + i].GetValue();
        }

        // Rememember that we did copy the partitions, so that we will do the actual merging now.
        this->coppied = true;

        // Initialize the indeces for merging.
        this->a = this->b = 0;
        this->free = low;
    }

    if (a < left_len && b < right_len) {
        if (left_tmp[a] < right_tmp[b]) {
            // In case the left_tmp has smaller element, store that one in the main array.
            this->arr[free].SetValue(left_tmp[a++]);
            this->arr[free++].SetFocus(RED);
        }
        else {
            // Otheriwse store the element from the right_tmp.
            this->arr[free].SetValue(right_tmp[b++]);
            this->arr[free++].SetFocus(RED);
        }
    }
    else {
        // In case there is an array that we haven't merged yet completely, then add all of its elements to the array.
        if (a < left_len) {
            this->arr[free].SetValue(left_tmp[a++]);
            this->arr[free++].SetFocus(RED);
        }
        else if (b < right_len) {
            this->arr[free].SetValue(right_tmp[b++]);
            this->arr[free++].SetFocus(RED);
        }
        else {
            // Otherwise conclude the merging process.
            this->merge_done = true;
        }
    }
}

void MergeSort::Step() {
    if (partition_size <= this->ArraySize() - 1) {
        if (low < this->ArraySize() - 1) {
            // Calculate the boundaries for the left and the right partition, merge both of them.
            int mid = std::min(low + partition_size - 1, this->ArraySize() - 1);
            int high = std::min(low + 2 * partition_size - 1, this->ArraySize() - 1);
            this->Merge(low, mid, high);

            if (this->merge_done) {
                // In case the merge is completed, move to the first element after the right partition.
                low = low + 2 * partition_size;
                this->merge_done = false;
                this->coppied = false;
            }
        }
        else {
            // In case we went through all the partitions of the current size, we will go through partitions of the current size * 2.
            partition_size = 2 * partition_size;
            this->low = 0;
        }

        return;
    }

    // In case we went through all the partitions and merged them, then we are done.
    this->finished = true;
}

