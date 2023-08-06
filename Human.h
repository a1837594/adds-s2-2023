#ifndef HUMAN_H
#define HUMAN_H

#include "Player.h"

class Human : public Player {
    private:
    std::string name;
    Move* chosenMove;
    public:
    Human();
    explicit Human(const std::string& playerName);
    Move* makeMove() override;
    std::string getName() override;
    ~Human();
};

#endif
