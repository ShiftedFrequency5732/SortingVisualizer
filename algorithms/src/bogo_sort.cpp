#include "../include/bogo_sort.hpp"

namespace Algorithms {
    void BogoSort::Prepare() {
        // Set the iterator for shuffling to be at the last element, and for checking if the elements are sorted at the start.
        this->i_shuffle = this->ArraySize() - 1;
        this->j_check = 0;
    }

    void BogoSort::Step() {
        if (i_shuffle >= 1) {
            // For each element, (except the first one), that has the index i, generate a new index in the range [0, i].
            // We won't do this for the first element, as that element will always get the newly generated index to be 0.
            int new_index = GetRandomValue(0, this->i_shuffle);

            // Swap the elements at the current index i and newly generated index.
            Element temp = this->arr[i_shuffle];
            this->arr[i_shuffle] = this->arr[new_index];
            this->arr[new_index] = temp;

            // Color the elements RED.
            this->arr[i_shuffle].SetFocus(RED);
            this->arr[new_index].SetFocus(RED);

            // Move to the previous element to generate new index.
            --this->i_shuffle;
            return;
        }
        else if (this->j_check < this->ArraySize() - 1) {
            // Color the two elements that we will compare with red.
            this->arr[j_check].SetFocus(RED);
            this->arr[j_check + 1].SetFocus(RED);

            if (this->arr[j_check] > this->arr[j_check + 1]) {
                // If the elements aren't sorted, start over with shuffling.
                this->Prepare();
            }
            else {
                // If the current elements are sorted, move to the next element to check further.
                ++this->j_check;
            }

            return;
        }

        // If the array is sorted, we finished.
        this->finished = true;
    }
}

