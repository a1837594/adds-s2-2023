#include "Human.h"
#include "Computer.h"
#include "Referee.h"
#include "Move.h"
#include <iostream>
#include <ctime>
#include <cstdlib>

int main() {
    srand(time(nullptr)); // Seed the random number generator

    Human mei("Mei");
    Computer computer;

    Referee referee;
    Player* winner = referee.refGame(&mei, &computer);

    if (winner == nullptr) {
        std::cout << "It's a Tie" << std::endl;
    } else {
        std::cout << winner->getName() << " Wins" << std::endl;
    }

    return 0;
}

