#pragma once

class stats
{
    public:
    stats(){};
    ~stats(){};

    float health,attack,defense,speed,critical,currentExp,expNeeded;

    protected:
    int level;
};
