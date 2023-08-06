#ifndef HUMAN_H
#define HUMAN_H

#include "Player.h"
#include <string>

class Human : public Player {
private:
    std::string name;

public:
    Human(const std::string& playerName = "Human");
    Move* makeMove() override;
    std::string getName() override;
};

#endif // HUMAN_H
