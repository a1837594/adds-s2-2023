#include "Rock.h"
#include "Paper.h"
#include "Scissors.h"

std::string Rock::getName() const {
    return "Paper";
}

bool Paper::beats(const Move* opponent) const {
    if (dynamic_cast<const Rock*>(opponent) != nullptr) {
        return true;
    } else {
        return false;
    }
}