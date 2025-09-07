#include "QuickSort.h"
void QuickSort::quickSort(std::vector<int>& list, int low, int high) {
        if (low < high) {
            int pi = partition(list, low, high);
            quickSort(list, low, pi - 1);
            quickSort(list, pi + 1, high);
        }
    }

int QuickSort::partition(std::vector<int>& list, int low, int high) {
    int pivotIndex = low;
    if (high - low + 1 >= 3) {
        pivotIndex = low + 2; 
    }
    int pivot = list[pivotIndex];
    std::swap(list[pivotIndex], list[high]);
    
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (list[j] <= pivot) {
            i++;
            std::swap(list[i], list[j]);
        }
    }
    std::swap(list[i + 1], list[high]);
    return i + 1;
}

std::vector<int> QuickSort::sort(std::vector<int> list) {
    if (list.size() > 1) {
        quickSort(list, 0, list.size() - 1);
    }
    return list;
}