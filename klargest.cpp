#include <vector>
#include <queue>


int kth_largest(std::vector<int> values, int k)
{
    if (k <= 0 || values.empty()) {
        if (k > values.size() || k <= 0) {
            if (values.empty()) return 0;
            k = values.size();
        }
    }
    std::priority_queue<int, std::vector<int>, std::greater<int>> min;
    for (int value : values){
        min.push(value);
        if (min.size() > k)min.pop();
    }
    return min.top();
}
