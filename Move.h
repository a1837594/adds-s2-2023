#ifndef MOVE_H
#define MOVE_H

#include <string>

class Move{
    protected:
    std::string name;
    public:
    virtual std::string getName()=0;
    virtual bool beats(Move *opp)=0;  
};

class Scissors: public Move{
    private:
    std::string name;
    public:
    Scissors();
    std::string getName() override;
    bool beats(Move *opp) override;
};

class Paper: public Move{
    private:
    std::string name;
    public:
    Paper();
    std::string getName() override;
    bool beats(Move *opp) override;
};

class Rock: public Move{
    private:
    std::string name;
    public:
    Rock();
    std::string getName() override;
    bool beats(Move *opp) override;
};

#endif