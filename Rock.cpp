#include "Rock.h"
#include "Paper.h"
#include "Scissors.h"

std::string Rock::getName() const {
    return "Rock";
}

bool Rock::beats(const Move* opponent) const {
    // Rock beats Scissors
    if (dynamic_cast<const Scissors*>(opponent) != nullptr) {
        return true;
    } else {
        return false;
    }
}
