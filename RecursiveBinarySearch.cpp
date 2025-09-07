#ifndef RECURSIVEBINARYSEARCH_H
#define RECURSIVEBINARYSEARCH_H
#include "RecursiveBinarySearch.h"

bool RecursiveBinarySearch::search(const std::vector<int>& list, int target) {
    return Helper(list, target, 0, list.size() - 1) != -1;
}

int RecursiveBinarySearch::Helper(const std::vector<int>& list, int target, int left, int right) {
    if (left > right) return -1;
    int mid = left + (right - left) / 2;
    if (list[mid] == target) return mid;
    if (target < list[mid])
        return Helper(list, target, left, mid - 1);
    else
        return Helper(list, target, mid + 1, right);
}
#endif // RECURSIVEBINARYSEARCH_H