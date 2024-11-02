//
//  BigInt.cpp
//  cplusTimu
//
//  Created by zhuzhuxia on 2024/10/22.
//

    
#include "BigInt.hpp"


    // 去掉前导零
    void BigInt::removeLeadingZeros() {
        while (number.length() > 1 &&
               number[0] == '0') {
            number.erase(0, 1);
        }
    }
    
    // 构造函数
    //成员初始化列表（: name_(name), age_(age)）来初始化成员变量
    BigInt::BigInt(const std::string& num) : number(num){
        removeLeadingZeros();
    }

    // 加法
    BigInt BigInt::operator+(const BigInt& other) const {
        std::string a = number;
        std::string b = other.number;
        std::string result;
        int carry = 0;

        if (a.length() < b.length()) std::swap(a, b);

        for (int i = 0; i < a.length(); ++i) {
            int digitA = a[a.length() - 1 - i] - '0';
            int digitB = (i < b.length()) ? b[b.length() - 1 - i] - '0' : 0;
            int sum = digitA + digitB + carry;
            carry = sum / 10;
            result.push_back((sum % 10) + '0');
        }
        if (carry) result.push_back(carry + '0');

        std::reverse(result.begin(), result.end());
        return BigInt(result);
    }

    // 减法
    BigInt BigInt::operator-(const BigInt& other) const {
        std::string a = number;
        std::string b = other.number;
        std::string result;
        int borrow = 0;

        for (int i = 0; i < a.length(); ++i) {
            int digitA = a[a.length() - 1 - i] - '0';
            int digitB = (i < b.length()) ? b[b.length() - 1 - i] - '0' : 0;
            int sub = digitA - digitB - borrow;
            if (sub < 0) {
                sub += 10;
                borrow = 1;
            } else {
                borrow = 0;
            }
            result.push_back(sub + '0');
        }
        std::reverse(result.begin(), result.end());
        return BigInt(result);
    }

    // 乘法
    BigInt BigInt::operator*(const BigInt& other) const {
        std::string a = number;
        std::string b = other.number;
        std::string result(a.length() + b.length(), '0');

        for (int i = a.length()-1; i >= 0; --i) {
            int carry = 0;
            for (int j = b.length()-1; j >= 0; --j) {
                int mul = (a[i] - '0') * (b[j] - '0') + (result[i + j + 1] - '0') + carry;
                carry = mul / 10;
                result[i + j + 1] = (mul % 10) + '0';
            }
            result[i] += carry;
        }

        BigInt res(result);
        res.removeLeadingZeros();
        return res;
    }

    // 除法
    BigInt BigInt::operator/(const BigInt& other) const {
        std::string a = number;
        std::string b = other.number;

        if (other == BigInt("0")) throw std::invalid_argument("Division by zero!");

        BigInt current("0");
        std::string result;
        for (size_t i = 0; i < a.size(); ++i) {
            current = current * BigInt("10") + BigInt(std::string(1, a[i]));
            int count = 0;
            while (current >= other) {
                current = current - other;
                count++;
            }
            result.push_back(count + '0');
        }

        BigInt res(result);
        res.removeLeadingZeros();
        return res;
    }

    // 取模
    BigInt BigInt::operator%(const BigInt& other) const {
        BigInt quotient = *this / other;
        BigInt remainder = *this - quotient * other;
        return remainder;
    }

    // 比较运算符重载
    bool BigInt::operator==(const BigInt& other) const {
        return number == other.number;
    }

    bool BigInt::operator>=(const BigInt& other) const {
        return (*this > other || *this == other);
    }

//    bool BigInt::operator<=(const BigInt& other) const {
//        return ( *this < other || *this == other);
//    }

    bool BigInt::operator>(const BigInt& other) const {
        if (number.length() != other.number.length())
            return number.length() > other.number.length();
        return number > other.number;
    }

    // 输出
 std::ostream& operator<<(std::ostream& os, const BigInt& bigInt) {
        os << bigInt.number;
        return os;
    }

