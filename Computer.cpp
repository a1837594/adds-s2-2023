#include "Computer.h"

Move* Computer::makeMove() {
    return new Rock();
}

std::string Computer::getName() {
    return "Computer";
}
