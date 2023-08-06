#include "Human.h"

Human::Human(const std::string& playerName) : name(playerName) {}

Move* Human::makeMove() {
    std::string moveName;
    std::cout << "Enter Move: ";
    std::cin >> moveName;

    // Create and return the corresponding Move object based on user input
    if (moveName == "Rock") {
        return new Rock();
    } else if (moveName == "Paper") {
        return new Paper();
    } else if (moveName == "Scissors") {
        return new Scissors();
    } else if (moveName == "Robot") {
        return new Robot();
    } else if (moveName == "Monkey") {
        return new Monkey();
    } else if (moveName == "Pirate") {
        return new Pirate();
    } else if (moveName == "Ninja") {
        return new Ninja();
    } else if (moveName == "Zombie") {
        return new Zombie();
    }

    // Return nullptr if the input is not recognized
    return nullptr;
}

std::string Human::getName() {
    return name;
}

