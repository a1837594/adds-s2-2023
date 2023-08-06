#ifndef ROCK_H
#define ROCK_H

#include "Move.h"

class Rock : public Move {
public:
    std::string getName() const override;
    bool beats(const Move* opponent) const override;
};

#endif // ROCK_H
