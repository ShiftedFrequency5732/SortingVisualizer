#include "../include/quick_sort.hpp"
#include <iostream>

void QuickSort::Prepare() {
    // At the start, clear the stack, and we will run the partitioning on the whole array, so add the { 0, n - 1 } to the stack.
    this->ranges = std::stack<std::pair<int, int>>();
    this->ranges.push({ 0, this->ArraySize() - 1 });

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
        // After that the elements that the left and right ptrs point to may be swapped, if pointers still point to the valid range.
        this->left_checked = false;
        this->right_checked = false;
        this->valid_ptrs = false;
    }

    if (this->left < this->right) {
        // Check if pointers are valid.
        this->valid_ptrs = true;
    }

    if (this->valid_ptrs) {
        if (!this->left_checked) {
            // If we still didn't finish checking the left parttition, check it.
            // Move the left pointer forwards as long as it points to the element that is lesser than (or equal to) the pivot, color that element red.
            if (this->arr[left] <= pivot && left < right) {
                this->arr[left].SetFocus(RED);
                ++this->left;
                return;
            }
            else {
                this->left_checked = true;
            }
        }

        if (!this->right_checked) {
            // If we still didn't finish checking the right partition, check it.
            // Move the right pointer backwards as long as it points to the greater element than the pivot, color that element red.
            if (this->arr[right] > pivot) {
                this->arr[right].SetFocus(RED);
                --this->right;
                return;
            }
            else {
                this->right_checked = true;
            }
        }

        if (this->left < this->right) {
            // If did check both left and right partitions, reset the flags as we will check them again.
            this->left_checked = false;
            this->right_checked = false;
            this->valid_ptrs = false;

            // If pointers are in the valid range, they point to elements that do not belong to their respective partition, swap them.
            Element temp = this->arr[this->left];
            this->arr[this->left] = this->arr[this->right];
            this->arr[this->right] = temp;

            // Color the elements red.
            this->arr[this->left].SetFocus(RED);
            this->arr[this->right].SetFocus(RED);
            return;
        }
    }

    // At this point, the right is lesser than the left, and it points to the last element of the left partition.
    // Which is the element that is lesser or equal to the pivot. Swap the pivot at the low with that element.
    this->arr[low] = this->arr[right];
    this->arr[right] = pivot;
    pivot_index = right;

    // Color both elements to the RED.
    this->arr[right].SetFocus(RED);
    this->arr[low].SetFocus(RED);

    // Remember that we did partition this range. The pivot is now sorted.
    // Everything to the left of it is lesser than or equal to it, and everything to the right is greater than it.
    this->done_partitioning = true;
}

void QuickSort::Step() {
    while (this->done_partitioning && !ranges.empty()) {
        // If we finished partitioning in the previous round, and if we still have the ranges to cover, take one range from the stack.
        std::pair<int, int> r = ranges.top();
        ranges.pop();

        this->low = r.first;
        this->high = r.second;

        if (this->low == this->high) {
            // If this range contains only one element, color it blue, it is for sure sorted. Try picking range again.
            this->arr[this->low].SetFocus(BLUE, false);
        }

        if (this->low < this->high) {
            // Reset the boolean flags so that we will perform the quick sort again, exit the loop.
            this->done_partitioning = false;
            this->pivot_set = false;
            break;
        }
    }

    if (this->done_partitioning && ranges.empty()) {
        // If we finished partitioning the subarray in the previous round, and if we are out of ranges, then we are done.
        finished = true;
        return;
    }

    // Step the partition.
    this->Partition();

    if (this->done_partitioning) {
        // If we did partition the array, color the pivot blue, as it is for sure sorted.
        this->arr[pivot_index].SetFocus(BLUE, false);

        // Add to the stack of ranges both ranges, but smaller one first, so we will abuse the stack less.
        if ((pivot_index - 1) - low + 1 <= high - (pivot_index + 1) + 1) {
            ranges.push({ low, pivot_index - 1 });
            ranges.push({ pivot_index + 1, high});
        }
        else {
            ranges.push({ pivot_index + 1, high});
            ranges.push({ low, pivot_index - 1 });
        }
    }
}

