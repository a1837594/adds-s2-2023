#include "Move.h"

Move::Move(const std::string& moveName) : name(moveName) {}

std::string Move::getName() {
    return name;
}

Rock::Rock() : Move("Rock") {}

bool Rock::beats(Move* otherMove) {
    return (dynamic_cast<Scissors*>(otherMove) != nullptr);
}

Paper::Paper() : Move("Paper") {}

bool Paper::beats(Move* otherMove) {
    return (dynamic_cast<Rock*>(otherMove) != nullptr);
}

Scissors::Scissors() : Move("Scissors") {}

bool Scissors::beats(Move* otherMove) {
    return (dynamic_cast<Paper*>(otherMove) != nullptr);
}

Robot::Robot() : Move("Robot") {}

bool Robot::beats(Move* otherMove) {
    return (dynamic_cast<Zombie*>(otherMove) != nullptr || dynamic_cast<Ninja*>(otherMove) != nullptr);
}
