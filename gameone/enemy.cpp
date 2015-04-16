#include "enemy.h"
//----------------------
void enemy::setArrays()
{
    string directory;
    for(int i=0;i<11;i++)  //attacking sprites
        {
            stringstream temp;
            temp <<"images/Enemys/Croc/"<<i<<".png";
            directory = temp.str();
            attackR[i].loadFromFile(directory);
        }
}
void  enemy::setStats()
{
    level=1;
    health=100;
    attack=3.5;
    speed=3.5;
    defense=3.5;
    critical=1.5;

}
