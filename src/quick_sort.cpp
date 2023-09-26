#include "../include/quick_sort.hpp"
#include <iostream>

void QuickSort::Prepare() {
    // At the start, clear the stack, and we will run the partitioning on the whole array, so add the { 0, n - 1 } to the stack.
    this->ranges = std::stack<std::pair<int, int>>();
    this->ranges.push({ 0, N_ELEMENTS - 1 });

    // Auxiliary variables for the quick sort.
    this->done_partitioning = true;
    this->pivot_set = false;
    this->left_checked = false;
    this->right_checked = false;
}

void QuickSort::Partition() {
    if (!this->pivot_set)  {
        // The pivot will be the lowest element. Remember that we did set it, so that we can do the partitioning.
        this->pivot = this->arr[this->low];
        this->pivot_set = true;

        // Initialize the pointers for partitioning.
        this->left = this->low;
        this->right = this->high;

        // Initialize the flags to false, we must first check if the pointers are valid (once), THEN check the left partition (fully) AND THEN the right partition (fully).
        // After that the elements that the left and right ptrs point to may be swapped.
        this->left_checked = false;
        this->right_checked = false;
        this->valid_ptrs = false;
        return;
    }

    if (this->left < this->right) {
        // Check if pointers are valid.
        this->valid_ptrs = true;
    }

    if (this->valid_ptrs) {
        if (!this->left_checked) {
            // If we still didn't finish checking left parttition, check it.
            // Move the left pointer as long as it points to the elements that is lesser than (or equal to) the pivot.
            if (this->arr[left] <= pivot && left < right) {
                this->arr[left].SetFillColor(RED);
                ++this->left;
            }
            else {
                this->left_checked = true;
            }
            return;
        }

        if (!this->right_checked) {
            // If we still didn't finish checking the right partition, check it.
            // Move the right pointer as long as it points to the greater element than the pivot.
            if (this->arr[right] > pivot) {
                this->arr[right].SetFillColor(RED);
                --this->right;
            }
            else {
                this->right_checked = true;
            }
            return;
        }

        if (this->left < this->right) {
            // If did check both left and right sides, reset the flags as we will check them again.
            // Reset the valid_ptrs flag as well, as we want to check if the pointers are still valid.
            this->left_checked = false;
            this->right_checked = false;
            this->valid_ptrs = false;

            // If pointers are in the valid range, they point to elements that do not belong to their respective partition, swap them.
            Element temp = this->arr[this->left];
            this->arr[this->left] = this->arr[this->right];
            this->arr[this->right] = temp;

            // Color the elements red.
            this->arr[this->left].SetFillColor(RED);
            this->arr[this->right].SetFillColor(RED);
            return;
        }
    }

    // At this point, the right is lesser than left, and it points to the last element of the left partition.
    // Which is the element that is lesser or equal to the pivot. Swap the pivot at the low with that element.
    this->arr[low] = this->arr[right];
    this->arr[right] = pivot;
    pivot_index = right;

    // Color both elements to the RED.
    this->arr[right].SetFillColor(RED);
    this->arr[low].SetFillColor(RED);

    // Remember that we did partition this range. The pivot is now sorted.
    // As everything to the left is lesser than or equal to it, and everything to the right is greater than it.
    this->done_partitioning = true;
}

void QuickSort::Step() {
    if (this->done_partitioning && !ranges.empty()) {
        // If we finished partitioning in the previous round, and if we still have ranges to cover, take one range from the stack.
        std::pair<int, int> r = ranges.top();
        ranges.pop();

        low = r.first;
        high = r.second;

        if (low == high) {
            // If this range contains only one element, color it blue, it is for sure sorted. And try picking range again.
            this->arr[low].SetFillColor(BLUE, false);
            return;
        }
        else if (low > high) {
            // If the range we picked is invalid, try again.
            return;
        }

        // Reset the boolean flags so that we will perform the quick sort again.
        this->done_partitioning = false;
        this->pivot_set = false;
    }
    else if (this->done_partitioning && ranges.empty()) {
        // If we finished partitioning the subarray in the previous round, and we are out of ranges, then we are done.
        finished = true;
        return;
    }

    // Step the partition.
    this->Partition();

    if (this->done_partitioning) {
        // If we did partition the array, color the pivot blue, as it is for sure sorted.
        this->arr[pivot_index].SetFillColor(BLUE, false);

        // Add to the stack of ranges both ranges, but smaller one first, so we won't have as many ranges in it.
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

