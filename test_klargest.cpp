#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <functional>
#include <limits>
#include <ctime>

// Include the function definition here for the test file to be runnable.
int kth_largest(std::vector<int> values, int k)
{
    // Edge case handling for k being out of bounds or invalid
    if (k <= 0 || values.empty()) {
        if (values.empty()) return 0;
        k = values.size(); // Default to the smallest element
    }
    
    if (k > values.size()) {
        k = values.size(); // If k is too large, find the smallest element
    }

    // Min-Heap (priority_queue with std::greater) of size k.
    std::priority_queue<int, std::vector<int>, std::greater<int>> min_heap;

    for (int value : values)
    {
        min_heap.push(value);

        if (min_heap.size() > k)
        {
            min_heap.pop();
        }
    }

    return min_heap.top();
}


void run_test(const std::vector<int>& values, int k, int expected) {
    int result = kth_largest(values, k);
    std::cout << "Values size: " << values.size() << ", k=" << k << ". ";
    
    if (values.size() <= 10) {
        std::cout << "Input: [";
        for (size_t i = 0; i < values.size(); ++i) {
            std::cout << values[i] << (i == values.size() - 1 ? "" : ", ");
        }
        std::cout << "]. ";
    }


    if (result == expected) {
        std::cout << "SUCCESS: Result = " << result << " (Expected: " << expected << ")" << std::endl;
    } else {
        std::cout << "FAILURE: Result = " << result << " (Expected: " << expected << ")" << std::endl;
    }
}

int main() {
    std::cout << "--- Testing kth_largest with Duplicates and Large Data ---" << std::endl;

    // Test Case 1: Duplicates at the k-th position
    std::vector<int> test1 = {1, 5, 2, 5, 4, 3, 5, 6};
    // Sorted: 6, 5, 5, 5, 4, 3, 2, 1. 3rd largest is 5.
    run_test(test1, 3, 5); 
    // 4th largest is 5.
    run_test(test1, 4, 5);
    // 5th largest is 4.
    run_test(test1, 5, 4); 

    // Test Case 2: Mix of positive and negative numbers
    std::vector<int> test2 = {10, -5, 20, 0, -1, 30, 5};
    // Sorted: 30, 20, 10, 5, 0, -1, -5. 4th largest is 5.
    run_test(test2, 4, 5); 
    // 6th largest is -1.
    run_test(test2, 6, -1);

    // Test Case 3: Large data set (Test performance and correctness)
    std::cout << "\n[Test 3: Large Dataset (100,000 elements)]" << std::endl;
    std::vector<int> large_data;
    // Populate with 100,000 numbers from 1 to 100,000 in reverse order
    for (int i = 100000; i >= 1; --i) {
        large_data.push_back(i);
    }
    // Shufflle for a true unsorted test
    std::random_shuffle(large_data.begin(), large_data.end());
    
    // 10th largest element is 99991
    run_test(large_data, 10, 99991); 
    
    // 1000th largest element is 99001
    run_test(large_data, 1000, 99001); 

    // The smallest element (100000th largest) is 1
    run_test(large_data, 100000, 1);
    
    return 0;
}
