#include <iostream>
#include "Player.h"
#include "Human.h"
#include "Computer.h"
#include "Referee.h"

int main() {
    // Create players
    Player* humanPlayer = new Human("Mei");
    Player* computerPlayer = new Computer();

    // Create referee
    Referee referee;

    // Get the winning player
    Player* winner = referee.refGame(humanPlayer, computerPlayer);

    // Determine the winner
    if (winner == nullptr) {
        std::cout << "It's a Tie\n";
    } else {
        std::cout << winner->getName() << " Wins\n";
    }

    // Clean up
    delete humanPlayer;
    delete computerPlayer;

    return 0;
}
