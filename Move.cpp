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