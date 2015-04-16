#include "..\include\movement.h"
#include "..\include\stats.h"
//---------------------------------------------------
class player: movementArrays,stats
{
    public:
    player(){setStats();setArrays();}
    ~player(){}

    sf::Clock timer;
    sf::Texture& loadSprite(char,int);
    void setArrays();
    void setStats();
    void updateStats();
    void calcExp();
    float getStats();

};
