#include "Sort.h"
#include <vector>
#include <iostream>
#include <string>
#include "BubbleSort.h"
#include "QuickSort.h"
using namespace std;

bool binarySearch(const std::vector<int>& list, int target) {
    int left = 0, right = list.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (list[mid] == target) return true;
        if (list[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return false;
}

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
    
    bool hasOne = binarySearch(sorted, 1);
    
    std::cout << (hasOne ? "true" : "false");
    for (int x : sorted) {
        std::cout << " " << x;
    }
    std::cout << std::endl;
    
    return 0;
}