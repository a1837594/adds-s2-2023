#ifndef REVERSER_H
#define REVERSER_H

#include <string>

class Reverser{
    public:
    int reverseDigit(int value);
    std::string reverseString(std::string characters);
    std::string reverseString(std::string characters,int stat);
};

#endif