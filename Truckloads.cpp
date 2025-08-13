#include <iostream>

class Truckloads{
public:
    int numTrucks(int numCrates, int Loadsize){
        int temp = numCrates / 2;
        if(numCrates <= Loadsize) return 1;
        if(numCrates <= Loadsize * 2) return 2;
        if(numCrates%2){
            return numTrucks(temp, Loadsize) + numTrucks(temp + 1, Loadsize);
        } else {
            return numTrucks(temp, Loadsize) * 2 ;
        }
    };
};

int main(){
    int num, size;
    std::cin >> num >> size;
    Truckloads truckloads;
    std::cout << truckloads.numTrucks(num, size) << std::endl;
    return 0;
}