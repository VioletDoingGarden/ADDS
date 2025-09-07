#ifndef QUICKSORT_H
#define QUICKSORT_H
#include "Sort.h"


class QuickSort : public Sort {
public:
    void quickSort(std::vector<int>& list, int low, int high);

    int partition(std::vector<int>& list, int low, int high);

    std::vector<int> sort(std::vector<int> list) override ;
};

#endif // QUICKSORT_H