#include "Human.h"

#include <iostream>

Human::Human() : name("Human") {}

Human::Human(const std::string& playerName) : name(playerName) {}

Move* Human::makeMove() {
    std::string input;
    //std::cout << "Enter your move ";
    std::cin >> input;

    if (input == "Scissors") {
        return new Scissors();
    } else if (input == "Paper") {
        return new Paper();
    } else if (input == "Rock") {
        return new Rock();
    }
}

std::string Human::getName() {
    return name;
}
