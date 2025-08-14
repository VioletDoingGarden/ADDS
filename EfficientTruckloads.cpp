#include <iostream>
#include "EfficientTruckloads.h"

int Truckloads::numTrucks(int numCrates, int Loadsize, std::vector<int>& mem){
    if(mem[numCrates] != -1) return mem[numCrates];
    if(numCrates <= Loadsize) {
        mem[numCrates] = 1;
        return 1;
    }
    if(numCrates <= Loadsize * 2) {
        mem[numCrates] = 2;
        return 2;
    }
    if(numCrates%2){
        mem[numCrates] = numTrucks(numCrates / 2, Loadsize,  mem) + numTrucks(numCrates / 2 + 1, Loadsize, mem);
    } else {
        mem[numCrates] = numTrucks(numCrates / 2, Loadsize, mem) * 2 ;
    }
    return mem[numCrates];
};


// int main(){
//     std::vector<int> mem(1001, -1); // Assuming numCrates won't exceed 1000
//     int num, size;
//     std::cin >> num >> size;
//     Truckloads truckloads;
//     std::cout << truckloads.numTrucks(num, size,mem) << std::endl;
//     return 0;
// }