#include "Move.h"
#include <iostream>
#include <string>
using namespace std;

Scissors::Scissors(): name("Scissors"){};

string Scissors::getName(){
    return this->name;
}

bool Scissors::beats(Move *opp) {
    if (dynamic_cast<Paper*>(opp)) {
        return true;
    }
    return false;
}

Paper::Paper(): name("Paper"){};

string Paper::getName(){
    return this->name;
}

bool Paper::beats(Move *opp) {
    if (dynamic_cast<Rock*>(opp)) {
        return true;
    }
    return false;
}

Rock::Rock(): name("Rock"){};

string Rock::getName(){
    return this->name;
}

bool Rock::beats(Move *opp) {
    if (dynamic_cast<Scissors*>(opp)) {
        return true;
    }
    return false;
}

Monkey::Monkey(): name("Monkey"){};

string Monkey::getName(){
    return this->name;
}

bool Monkey::beats(Move *opp) {
    if (dynamic_cast<Ninja*>(opp)||dynamic_cast<Robot*>(opp)) {
        return true;
    }
    return false;
}

Robot::Robot(): name("Robot"){};

string Robot::getName(){
    return this->name;
}

bool Robot::beats(Move *opp) {
    if (dynamic_cast<Ninja*>(opp)||dynamic_cast<Zombie*>(opp)) {
        return true;
    }
    return false;
}

Ninja::Ninja(): name("Ninja"){};

string Ninja::getName(){
    return this->name;
}

bool Ninja::beats(Move *opp) {
    if (dynamic_cast<Pirate*>(opp)||dynamic_cast<Zombie*>(opp)) {
        return true;
    }
    return false;
}

Pirate::Pirate(): name("Pirate"){};

string Pirate::getName(){
    return this->name;
}

bool Pirate::beats(Move *opp) {
    if (dynamic_cast<Monkey*>(opp)||dynamic_cast<Robot*>(opp)) {
        return true;
    }
    return false;
}

Zombie::Zombie(): name("Zombie"){};

string Zombie::getName(){
    return this->name;
}

bool Zombie::beats(Move *opp) {
    if (dynamic_cast<Monkey*>(opp)||dynamic_cast<Pirate*>(opp)) {
        return true;
    }
    return false;
}