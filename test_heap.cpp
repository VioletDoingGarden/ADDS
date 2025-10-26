#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>
// Include the implementation file directly for template instantiation
#include "Heap.tpp" 

// Alias the template class for cleaner usage in main
template class Heap<int>;

void test_heap_edge_cases() {
    std::cout << "--- Testing Min-Heap Edge Cases (Heap<int>) ---" << std::endl;
    Heap<int> min_heap;

    // --- Test 1: Empty Heap Checks ---
    std::cout << "\n[Test 1: Empty Heap Checks]" << std::endl;
    std::cout << "Is empty: " << (min_heap.isHeapEmpty() ? "TRUE" : "FALSE") << std::endl;
    // getMin on empty heap should return max value (INT_MAX for int)
    std::cout << "getMin on empty: " << (min_heap.getMin() == std::numeric_limits<int>::max() ? "SUCCESS" : "FAILURE") << std::endl;
    // popTop on empty heap should return min value (INT_MIN for int - based on my previous popTop implementation)
    std::cout << "popTop on empty: " << (min_heap.popTop() == std::numeric_limits<int>::max() ? "SUCCESS (returns MAX)" : "FAILURE") << std::endl;
    min_heap.remove(10);
    std::cout << "Remove on empty: (Check console output for errors) SUCCESS" << std::endl;


    // --- Test 2: Single Element ---
    std::cout << "\n[Test 2: Single Element Operations]" << std::endl;
    min_heap.insert(42);
    std::cout << "After insert 42. Heap: ";
    min_heap.printHeap();
    if (min_heap.getMin() == 42) {
        std::cout << "getMin: SUCCESS" << std::endl;
    }
    min_heap.remove(42);
    std::cout << "After remove 42. Heap: ";
    min_heap.printHeap();
    if (min_heap.isHeapEmpty()) {
        std::cout << "Remove single: SUCCESS, heap is empty." << std::endl;
    }

    // --- Test 3: Complex Insertion and Root Removal ---
    std::cout << "\n[Test 3: Complex Insertion & Root Removal]" << std::endl;
    std::vector<int> elements = {50, 20, 10, 80, 5, 60, 30};
    for (int e : elements) {
        min_heap.insert(e);
    }
    std::cout << "Heap after insertions: ";
    min_heap.printHeap(); // Min should be 5

    // Remove the current root (5)
    std::cout << "Removing root (5)..." << std::endl;
    min_heap.remove(5);
    std::cout << "Heap after removing 5: ";
    min_heap.printHeap(); // New Min should be 10

    // Remove the new root (10) using popTop
    int popped = min_heap.popTop();
    if (popped == 10) {
        std::cout << "PopTop: SUCCESS. Popped 10." << std::endl;
    }
    std::cout << "Heap after popTop: ";
    min_heap.printHeap(); // New Min should be 20

    // Remove a deep element (80)
    std::cout << "Removing deep element (80)..." << std::endl;
    min_heap.remove(80);
    std::cout << "Heap after removing 80: ";
    min_heap.printHeap(); // Min should still be 20
    
    if (min_heap.getMin() == 20) {
        std::cout << "Final getMin: SUCCESS. Min is 20." << std::endl;
    } else {
        std::cout << "Final getMin: FAILURE. Expected 20, Got " << min_heap.getMin() << std::endl;
    }

}

int main() {
    test_heap_edge_cases();
    return 0;
}
