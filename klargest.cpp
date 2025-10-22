#include <vector>
#include <queue>
#include <iostream>

int kth_largest(std::vector<int> values, int k)
{
    if(values.empty())return 0;
    if(k <= 0 || static_cast<std::vector<int>::size_type>(k) > values.size())k = static_cast<int>(values.size());
    std::priority_queue<int, std::vector<int>, std::greater<int>> min_heap;
    for (int value : values){
        min_heap.push(value);
        if (min_heap.size() > static_cast<std::priority_queue<int, std::vector<int>, std::greater<int>>::size_type>(k)) {
            min_heap.pop();
        }
    }
    return min_heap.top();
}

int main() {
    std::vector<int> test_values = {3, 2, 1, 5, 6, 4};
    int k_val;
    for (int val : test_values) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
    k_val = 2;
    std::cout << k_val << "th largest element: " << kth_largest(test_values, k_val) << std::endl;
    k_val = 1;
    std::cout << k_val << "st largest element: " << kth_largest(test_values, k_val) << std::endl;
    k_val = 6;
    std::cout << k_val << "th largest element: " << kth_largest(test_values, k_val) << std::endl;
    k_val = 0;
    std::cout << "k=0 (invalid), " << kth_largest(test_values, k_val) << std::endl;
    k_val = 10;
    std::cout << "k=10 (too large), " << kth_largest(test_values, k_val) << std::endl;
    std::vector<int> empty_values = {};
    k_val = 3;
    std::cout << "Empty list, k=" << k_val << ": " << kth_largest(empty_values, k_val) << std::endl;
    return 0;
}
