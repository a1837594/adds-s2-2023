#include <vector>
#include <queue>

int kth_largest(std::vector<int> values, int k) {
    std::priority_queue<int> max_heap;

    for (int value : values) {
        max_heap.push(value);
    }

    for (int i = 0; i < k - 1; i++) {
        max_heap.pop();
    }

    return max_heap.top();
}
