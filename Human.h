#ifndef HUMAN_H
#define HUMAN_H

#include "Player.h"

class Human : public Player {
    private:
    std::string name;
    public:
    Human();
    explicit Human(const std::string& playerName);
    char makeMove() override;
    std::string getName() override;
};

#endif
