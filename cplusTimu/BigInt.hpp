//
//  BigInt.hpp
//  cplusTimu
//
//  Created by zhuzhuxia on 2024/10/22.


//#include <stdio.h>
#include <iostream>
#include <string>
#include <cmath>
//#include <climits>
#include <vector>
//#include <algorithm>

using namespace std;


class BigInt{
    
private:
    string number; //存储大数的字符串
    void removeLeadingZeros();
    
public:
    
    BigInt (const std::string &num);
    BigInt operator+(const BigInt& other) const;
    BigInt operator-(const BigInt& other) const;
    BigInt operator*(const BigInt& other) const;
    BigInt operator/(const BigInt& other) const;
    BigInt operator%(const BigInt& other) const;
    bool operator==(const BigInt& other) const;
    bool operator>=(const BigInt& other) const;
    bool operator>(const BigInt& other) const;

    friend std::ostream& operator<<(std::ostream& os, const BigInt& bigInt);
};



