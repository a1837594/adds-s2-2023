#include "Rock.h"
#include "Paper.h"
#include "Scissors.h"

std::string Rock::getName() const {
    return "Scissors";
}

bool Scissors::beats(const Move* opponent) const {
    if (dynamic_cast<const Paper*>(opponent) != nullptr) {
        return true;
    } else {
        return false;
    }
}