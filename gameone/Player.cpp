#include "player.h"

sf::Texture& player::loadSprite(char key,int i)
{
        switch(key)
        {
            case 'w':
                return walkF[i];
                break;
            case 'a':
                return walkL[i];
                break;
            case 'd':
                return walkR[i];
                break;
            case 's':
                return walkB[i];
                break;
            case 'A':
                return attackR[i];
                break;
        }
        return walkB[0];

}
void player::setArrays()
{
        string directory;
        for(int i=0;i<=7;i++)  //movement sprites
        {
            stringstream temp;
            temp <<"images/black knight/noncombat/walkR/0"<<i<<".png";
            directory = temp.str();
            walkR[i].loadFromFile(directory);
            temp.str( std::string() );
            temp.clear();

            temp <<"images/black knight/noncombat/walkL/0"<<i<<".png";
            directory = temp.str();
            walkL[i].loadFromFile(directory);
            temp.str( std::string() );
            temp.clear();

            temp <<"images/black knight/noncombat/walkB/0"<<i<<".png";
            directory = temp.str();
            walkB[i].loadFromFile(directory);
            temp.str( std::string() );
            temp.clear();

            temp <<"images/black knight/noncombat/walkF/0"<<i<<".png";
            directory = temp.str();
            walkF[i].loadFromFile(directory);
        }
        for(int i=0;i<13;i++)  //attacking sprites
        {
            stringstream temp;
            temp <<"images/black knight/combat/attackR/0"<<i<<".png";
            directory = temp.str();
            attackR[i].loadFromFile(directory);

        }
}
void  player::setStats()
{
    level=1;
    health=100;
    attack=3.5;
    speed=3.5;
    defense=3.5;
    critical=1.5;
    currentExp=0;
    expNeeded=25;
}
float player::getStats()
{
    return speed;
}
