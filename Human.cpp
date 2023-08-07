#include "Human.h"
#include <iostream>

Human::Human() : name("Human") {}

Human::Human(const std::string& playerName) : name(playerName) {}

char Human::makeMove() {
    std::cout << "Enter move: ";
    char move;
    std::cin >> move;
    return move;
}

std::string Human::getName() {
    return name;
}
