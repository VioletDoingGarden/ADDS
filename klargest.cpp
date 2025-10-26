#include <vector>
#include <queue>

int kth_largest(std::vector<int> values, int k)
{
    if(values.empty())return 0;
    if(k <= 0 || static_cast<std::vector<int>::size_type>(k) > values.size())k = static_cast<int>(values.size());
    std::priority_queue<int, std::vector<int>, std::greater<int>> min;
    for (int value : values){
        min.push(value);
        if (min.size() > static_cast<std::priority_queue<int, std::vector<int>, std::greater<int>>::size_type>(k)) {
            min.pop();
        }
    }
    return min.top();
};
