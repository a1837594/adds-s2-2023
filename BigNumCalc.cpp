#include "BigNumCalc.h"
#include <stdexcept>

std::list<int> BigNumCalc::buildBigNum(std::string numString) {
    std::list<int> result;
    for (char digit : numString) {
        result.push_back(digit - '0'); // Convert character to integer and add to the list
    }
    return result;
}

std::list<int> BigNumCalc::add(std::list<int> num1, std::list<int> num2) {
    std::list<int> sum;
    int carry = 0;

    while (!num1.empty() || !num2.empty() || carry != 0) {
        int x = 0, y = 0;
        
        if (!num1.empty()) {
            x = num1.back();
            num1.pop_back();
        }
        
        if (!num2.empty()) {
            y = num2.back();
            num2.pop_back();
        }

        int temp = x + y + carry;
        carry = temp / 10;
        sum.push_front(temp % 10);
    }

    return sum;
}

std::list<int> BigNumCalc::sub(std::list<int> num1, std::list<int> num2) {
    std::list<int> diff;
    int borrow = 0;

    while (!num1.empty() || !num2.empty()) {
        int x = 0, y = 0;

        if (!num1.empty()) {
            x = num1.back();
            num1.pop_back();
        }

        if (!num2.empty()) {
            y = num2.back();
            num2.pop_back();
        }

        int temp = x - y - borrow;

        if (temp < 0) {
            temp += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }

        diff.push_front(temp);
    }

    // Remove leading zeros
    while (diff.size() > 1 && diff.front() == 0) {
        diff.pop_front();
    }

    return diff;
}

std::list<int> BigNumCalc::mul(std::list<int> num1, std::list<int> num2) {
    if (num2.size() != 1) {
        throw std::invalid_argument("num2 must be a single-digit number for multiplication");
    }

    int digit = num2.front();
    if (digit == 0) {
        return std::list<int>{0}; // Multiplying by zero results in zero
    }

    std::list<int> product;
    int carry = 0;

    for (auto it = num1.rbegin(); it != num1.rend(); ++it) {
        int result = (*it * digit) + carry;
        carry = result / 10;
        product.push_front(result % 10);
    }

    if (carry > 0) {
        product.push_front(carry);
    }

    return product;
}
