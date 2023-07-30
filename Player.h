#ifndef PLAYER_H
#define PLAYER_H

#include <string>

class Player {//abstract class
public:
    virtual char makeMove() = 0;
    virtual std::string getName() = 0;
    virtual ~Player() {}
};

#endif
