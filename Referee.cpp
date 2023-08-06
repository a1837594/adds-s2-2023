#include "Referee.h"

Referee::Referee() {}

Player* Referee::refGame(Player* player1, Player* player2) {
    Move* move1 = player1->makeMove();
    Move* move2 = player2->makeMove();

    bool player1Wins = move1->beats(move2);
    bool player2Wins = move2->beats(move1);

    if (player1Wins) {
        return player1;
    } else if (player2Wins) {
        return player2;
    } else {
        return nullptr; // It's a tie
    }
}
