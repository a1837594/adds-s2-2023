#include "Reverser.h"
#include <iostream>
#include <string>

int Reverser::reverseDigit(int value){
    if (value < 10) {
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

std::string Reverser::reverseString(std::string characters){}