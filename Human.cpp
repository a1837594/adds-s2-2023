#include "Human.h"
#include "Rock.h" // Include the appropriate move classes
#include "Paper.h"
#include "Scissors.h"
#include <iostream>

Human::Human() : name("Human") {}

Human::Human(const std::string& playerName) : name(playerName) {}

Move* Human::makeMove() {
    if (chosenMove != nullptr) {
        delete chosenMove;
    }

    std::string userInput;
    std::cout << "Enter your move (Rock, Paper, or Scissors): ";
    std::cin >> userInput;

    // Create a new Move instance based on user input
    if (userInput == "Rock") {
        chosenMove = new Rock();
    } else if (userInput == "Paper") {
        chosenMove = new Paper();
    } else if (userInput == "Scissors") {
        chosenMove = new Scissors();
    } // Add other move types here
    
    return chosenMove;
}

std::string Human::getName() {
    return name;
}

Human::~Human() {
    if (chosenMove != nullptr) {
        delete chosenMove;
    }
}
