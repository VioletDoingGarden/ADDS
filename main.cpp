#include "Sort.h"
#include <vector>
#include <iostream>
#include <string>
#include "BubbleSort.h"
#include "QuickSort.h"
#include "RecursiveBinarySearch.h"

int main() {
    std::vector<int> numbers;
    int num;
    char c;
    while (std::cin >> num) {
        numbers.push_back(num);
        c = std::cin.get(); 
        if (c == '\n') break; 
    }
    
    QuickSort quick;
    std::vector<int> sorted = quick.sort(numbers);
    
    RecursiveBinarySearch rbs;
    bool hasOne = rbs.search(sorted, 1);
    
    std::cout << (hasOne ? "true" : "false");
    for (int x : sorted) {
        std::cout << " " << x;
    }
    std::cout << std::endl;
    
    return 0;
}