#include <iostream>
#include "Player.h"
#include "Human.h"
#include "Computer.h"
#include "Referee.h"

int main() {
    //insert name
    std::cout << "Enter your name: ";
    char name;
    std::cin >> name;

    //create players
    Player* human = new Human(name);
    Player* computer = new Computer();
    Referee referee;

    //compare
    Player* winner = referee.refGame(human, computer);

    //result
    if (winner == nullptr) {
        std::cout << "It's a Tie\n";
    } else {
        std::cout << winner->getName() << " Wins\n";
    }

    //delete
    delete human;
    delete computer;

    return 0;
}
