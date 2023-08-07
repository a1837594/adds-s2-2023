#ifndef COMPUTER_H
#define COMPUTER_H

#include "Player.h"

class Computer : public Player {
    private:
    std::string name;
    public:
    Computer();
    Move* makeMove() override;
    std::string getName() override;
};

#endif // COMPUTER_H
