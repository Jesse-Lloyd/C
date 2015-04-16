#include "Battle.h"
#include <sstream>
#include <string>
#include <iostream>
using namespace std;
//----------------------------------
void Battle::setButtonTextures()
{
    stringstream temp;
    string directory;
    for(int i=0;i<4;i++)
    {
        temp <<"images/Buttons/"<<i<<".png";
        directory = temp.str();
        buttons[i].loadFromFile(directory);
        temp.str(std::string());
        temp.clear();
    }
}
sf::Texture& Battle::loadButtonTexture(int i)
{
     return buttons[i];
}
