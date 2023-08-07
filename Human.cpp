#include "Human.h"

#include <iostream>

Human::Human(){
    std::cout << "Enter your name: ";
    char name;
    std::cin >> name;
    this->name=name;
}

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
    else if (input == "Ninja") {
        return new Ninja();
    }
    else if (input == "Robot") {
        return new Robot();
    }
    else if (input == "Pirate") {
        return new Pirate();
    }
    else if (input == "Monkey") {
        return new Monkey();
    }
    else if (input == "Zombie") {
        return new Zombie();
    }
}

std::string Human::getName() {
    return name;
}
