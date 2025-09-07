#include "Sort.h"
#include <vector>
#include <iostream>
#include <string>
#include "BubbleSort.h"
#include "QuickSort.h"
using namespace std;

bool isSorted(const std::vector<int>& list) {
    for (size_t i = 1; i < list.size(); ++i) {
        if (list[i - 1] > list[i]) return false;
    }
    return true;
}

int main() {
    BubbleSort bubble;
    QuickSort quick;

    std::vector<std::vector<int>> tests = {
        {},              
        {1},            
        {3, 1, 4, 2},   
        {5, 5, 5, 5},    
        {10, -1, 2, 8},  
        {1, 2, 3, 4, 5}, 
        {5, 4, 3, 2, 1}, 
        {2, 3, 2, 1, 4}, 
        {1, 2, 2, 3, 3},
        {2, 4, 9, 1}   
    };

    std::cout << "BubbleSort Tests:\n";
    for (const auto& test : tests) {
        auto result = bubble.sort(test);
        std::cout << "Input: [";
        for (size_t i = 0; i < test.size(); ++i) {
            std::cout << test[i] << (i < test.size() - 1 ? ", " : "");
        }
        std::cout << "] -> Sorted: " << (isSorted(result) ? "Pass" : "Fail") << "\n";
    }

    std::cout << "\nQuickSort Tests:\n";
    for (const auto& test : tests) {
        auto result = quick.sort(test);
        std::cout << "Input: [";
        for (size_t i = 0; i < test.size(); ++i) {
            std::cout << test[i] << (i < test.size() - 1 ? ", " : "");
        }
        std::cout << "] -> Sorted: " << (isSorted(result) ? "Pass" : "Fail") << "\n";
    }

    return 0;
}