#ifndef PLAYER_H
#define PLAYER_H

#include "Move.h"
#include <string>

class Player {//abstract class
public:
    virtual Move* makeMove() = 0;
    virtual std::string getName() = 0;//this will be used to save the players name
    virtual ~Player() {}
};

#endif
