#include "Reverser.h"
#include <iostream>
#include <string>
#include <typeinfo>

int Reverser::reverseDigit(int value){
    if(value<0){
        return -1;
    }
    else if (value < 10) {
        return value;
    } else {
        int lastDigit = value % 10;
        int remainingDigits = value / 10;

        int reversedRemaining = reverseDigit(remainingDigits);
        int numDigits = 1;

        int temp = remainingDigits;
        while (temp >= 10) {
            temp /= 10;
            numDigits++;
        }

        int multiplier = 1;
        for (int i = 0; i < numDigits; ++i) {
            multiplier *= 10;
        }

        return lastDigit * multiplier + reversedRemaining;
    }
}

std::string reverseString(std::string characters) {
    if (characters.empty()) {
        return "";
    } else {
        char firstChar = characters[0];
        std::string remainingChars = characters.substr(1);
        std::string reversedRemaining = reverseString(remainingChars);
        return reversedRemaining + firstChar;
    }
}

std::string reverseString(const char *input) {
    if (input == nullptr) {
        return "ERROR";
    }
    return reverseString(std::string(input));
}