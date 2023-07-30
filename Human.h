#ifndef HUMAN_H
#define HUMAN_H

#include "Player.h"

class Human : public Player {
public:
    Human();
    explicit Human(const std::string& playerName);
    char makeMove() override;
    std::string getName() override;
private:
    std::string name;
};

#endif // HUMAN_H
