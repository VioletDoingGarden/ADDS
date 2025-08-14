#include <vector>

class Truckloads{
public:
    std::vector<int> mem = std::vector<int>(5005, -1);
    int numTrucks(int numCrates, int Loadsize);
};
