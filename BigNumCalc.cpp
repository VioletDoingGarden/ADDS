#include "BigNumCalc.h"
#include <algorithm>

BigNumCalc::BigNumCalc() {}
BigNumCalc::~BigNumCalc() {}

std::list<int> BigNumCalc::buildBigNum(std::string numString) {
    std::list<int> res;
    for (char i : numString) {
        res.push_back(i - '0');
    }
    return res;
}

std::list<int> BigNumCalc::add(std::list<int> num1, std::list<int> num2) {
    std::list<int> res;
    int carry = 0;

    num1.reverse();
    num2.reverse();

    auto it1 = num1.begin();
    auto it2 = num2.begin();

    while (it1 != num1.end() || it2 != num2.end() || carry) {
        int sum = carry;
        if (it1 != num1.end()) {
            sum += *it1;
            ++it1;
        }
        if (it2 != num2.end()) {
            sum += *it2;
            ++it2;
        }
        res.push_front(sum % 10);
        carry = sum / 10;
    }
    
    while (res.size() > 1 && res.front() == 0) {
        res.pop_front();
    }
    
    return res;
}

std::list<int> BigNumCalc::sub(std::list<int> num1, std::list<int> num2) {
    std::list<int> res;
    int borrow = 0;
    
    num1.reverse();
    num2.reverse();

    auto it1 = num1.begin();
    auto it2 = num2.end();
    
    while (it1 != num1.end()){
        int digit2 = *it2; 
        if (it2 != num2.end()){
            it2++; 
        }else{
            digit2 = 0;
        }

        int digit1 = *it1 - borrow;
        

        if (digit2 > digit1){           
            digit1 = digit1 + 10;       
            borrow = 1;                  
        } else {
            borrow = 0;                 
        }
        int diff = digit1 - digit2;
        res.push_front(diff);
        it1++;
    }
    while (res.size() > 1 && res.front() == 0)
    {
        res.pop_front();
    }
    return res;

}

std::list<int> BigNumCalc::mul(std::list<int> num1, std::list<int> num2) {
    std::list<int> res;
    int multiplier = num2.back();
    int carry = 0;
    
    for (auto it = num1.begin(); it != num1.end(); ++it) {
        int product = (*it) * multiplier + carry;
        res.push_front(product % 10);
        carry = product / 10;
    }
    
    if (carry) {
        res.push_front(carry);
    }
    
    while (res.size() > 1 && res.front() == 0) {
        res.pop_front();
    }
    
    return res;
}