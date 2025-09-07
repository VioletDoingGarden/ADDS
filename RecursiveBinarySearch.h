
#include <vector>

class RecursiveBinarySearch {
public:
    bool search(const std::vector<int>& list, int target);
private:
    int Helper(const std::vector<int>& list, int target, int left, int right);
};