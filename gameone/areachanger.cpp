#include <math.h>
#include <SFML/Graphics.hpp>
#include "player.h"
#include <conio.h>
//-----------------------------------------------------------------------

using namespace std;

int collisionDetection(sf::Sprite& character,sf::Vector2f pos,int zone)
{
    //cout << " X = " << pos.x << endl <<" Y = " << pos.y << " zone = " << zone;

    const int SIZE = 1.33;
    const int VIEW_WIDTH = ceil(1200), VIEW_HEIGHT = ceil(600);

    sf::Vector2f cells(floor(pos.x / SIZE), floor(pos.y / SIZE));
    sf::Vector2f cellsNext = cells;
    int zoneNext = zone;

    if (cells.x >= VIEW_WIDTH )   //Right
    {
        if(zoneNext != 2 && zoneNext != 5 && zoneNext != 8)
        {
            cellsNext.x =0;
            zoneNext += 1;
        }
        else
            cellsNext.x = VIEW_WIDTH;
    }
    else if (cells.x <= 0 )   //Left
    {
        if(zoneNext != 0 && zoneNext != 3 && zoneNext != 6)
        {
            cellsNext.x = VIEW_WIDTH;
            zoneNext -= 1;
        }
        else
            cellsNext.x = 0;
    }
    if (cells.y >= VIEW_HEIGHT)  //Down
    {
        if(zoneNext < 6)
        {

            cellsNext.y = 0;
            zoneNext += 3;
        }
        else
        {
            cout << "In";
            cellsNext.y = VIEW_HEIGHT;
        }
    }
    else if (cells.y <= 0 )  //Up
    {
        if(zoneNext > 2)
        {
            cellsNext.y = VIEW_HEIGHT;
            zoneNext -= 3;
        }
        else
            cellsNext.y = 0;
    }
    character.setPosition(cellsNext.x * SIZE, cellsNext.y * SIZE);

    return zoneNext;
}
