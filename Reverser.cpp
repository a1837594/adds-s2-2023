#include "Reverser.h"
#include <iostream>
#include <typeinfo>
#include <string>

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

std::string Reverser::reverseString(std::string characters) {
    return reverseString(characters,characters.length());
}

std::string Reverser::reverseString(std::string characters,int stat) {
    if(typeid(characters) != typeid(std::string)){
        std::string erorr="ERROR";
        return erorr;
    }
    else if(stat==1){
        return characters;
    }
    else {
        char lastLetter=characters.back();
        characters.pop_back();
        characters.insert(characters.length()-stat,1,lastLetter);
        return reverseString(characters,stat--);
    }
}