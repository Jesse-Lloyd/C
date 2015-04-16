
#include "movement.h"
#include "stats.h"
//--------------------------------------------------------
class enemy: movementArrays,stats
{
    public:
    enemy(){setStats();setArrays();};
    ~enemy(){};

    void setArrays();
    void setStats();

    private:
};
