#ifndef MOVE_H
#define MOVE_H

#include <string>

class Move {
protected:
    std::string name;

public:
    Move(const std::string& moveName);
    std::string getName();
    virtual bool beats(Move* otherMove) = 0;
};

class Rock : public Move {
public:
    Rock();
    bool beats(Move* otherMove) override;
};

class Paper : public Move {
public:
    Paper();
    bool beats(Move* otherMove) override;
};

class Scissors : public Move {
public:
    Scissors();
    bool beats(Move* otherMove) override;
};

class Robot : public Move {
public:
    Robot();
    bool beats(Move* otherMove) override;
};

class Monkey : public Move {
public:
    Monkey();
    bool beats(Move* otherMove) override;
};

class Pirate : public Move {
public:
    Pirate();
    bool beats(Move* otherMove) override;
};

class Ninja : public Move {
public:
    Ninja();
    bool beats(Move* otherMove) override;
};

class Zombie : public Move {
public:
    Zombie();
    bool beats(Move* otherMove) override;
};

#endif // MOVE_H
