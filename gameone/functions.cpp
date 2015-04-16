#include <SFML/Graphics.hpp>
#include "area.h"
#include <sstream>
#include <string>
#include <iostream>

using namespace std;
//----------------------------------------------------------------------
string setAreaTexture(int t)
{
    string texture;
    stringstream temp;

    switch(t)
        {
            case 0:
                temp<<"images/Environment/groundtiles/area0.png";
                texture = temp.str();
                break;
            case 1:
                temp<<"images/Environment/groundtiles/area1.png";
                texture = temp.str();
                break;
            case 2:
                temp<<"images/Environment/groundtiles/area2.png";
                texture = temp.str();
                break;
            case 3:
                temp<<"images/Environment/groundtiles/area3.png";
                texture = temp.str();
                break;
            case 4:
                temp<<"images/Environment/groundtiles/area4.png";
                texture = temp.str();
                break;
            case 5:
                temp<<"images/Environment/groundtiles/area5.png";
                texture = temp.str();
                break;
            case 6:
                temp<<"images/Environment/groundtiles/area6.png";
                texture = temp.str();
                break;
            case 7:
                temp<<"images/Environment/groundtiles/area7.png";
                texture = temp.str();
                break;
            case 8:
                temp<<"images/Environment/groundtiles/area8.png";
                texture = temp.str();
                break;
            case 9:
                temp<<"images/Environment/groundtiles/battleArea.png";
                texture = temp.str();
                break;
        }
        return texture;
}
sf::Texture setFoliageTexture(int t)
{
    sf::Texture texture;
    switch(t)
    {
        case 0:
            texture.loadFromFile("images/Environment/groundtiles/single tiles/bush1.png");
            break;
        case 1:
            texture.loadFromFile("images/Environment/groundtiles/single tiles/bush2.png");
            break;
        case 2:
            texture.loadFromFile("images/Environment/groundtiles/single tiles/deadTree.png");
            break;
        case 3:
            texture.loadFromFile("images/Environment/groundtiles/single tiles/PineTree.png");
            break;
        case 4:
            texture.loadFromFile("images/Environment/groundtiles/single tiles/tree.png");
            break;
    }
    return texture;
}
int battleEncounter(int zone)
{
    int ranNum;
    ranNum = rand();
    srand(ranNum);
    if(ranNum <= 250 || ranNum >= 20000)
        zone =9;

    return zone;
}
