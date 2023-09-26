#include <stack>
#include "./algorithm.hpp"

class QuickSort : public Algorithm {
private:
    std::stack<std::pair<int, int>> ranges;
    int low, high;

    int curr_left, curr_right;
    bool done_left;
    bool done_right;

    bool confirmed;

    Element pivot;
    int pivot_index;
    bool have_pivot;

    bool done_partitioning;

    void Partition();

public:
    using Algorithm::Algorithm;

    void Prepare();
    void Step();
};
