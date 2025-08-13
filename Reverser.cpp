#include <string>
#include <cmath>
#include "Reverser.h"

int Reverser::reverseDigit(int value){
    if(value < 0) return -1; 
    int size = 0;
    for(int temp = value; temp > 0; temp /= 10) {
        size++;
    }
    if(value < 10) return value;
    // return reverseDigit(value / 10) ;
    return reverseDigit(value / 10)+ (value % 10) * pow(10,size - 1);
}
std::string Reverser::reverseString(std::string characters){
    if(characters.empty()) return "ERROR";
    if(characters.length() <= 1) return characters;
    return reverseString(characters.substr(1)) + characters[0];
}

// int main(){
//     Reverser r;
//     int reversedNumber = r.reverseDigit(12345);
//     std::cout << "Reversed Number: " << reversedNumber << std::endl;
//     std::string reversedString = r.reverseString("12345");
//     std::cout << "Reversed String: " << reversedString << std::endl;
//     return 0;
// }