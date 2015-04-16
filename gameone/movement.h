#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>
using namespace std;
//-------------------------------------------------
class movementArrays
{
    public:
    movementArrays(){}
    ~movementArrays(){}

    protected:
    sf::Texture walkR[9];
    sf::Texture walkL[9];
    sf::Texture walkF[9];
    sf::Texture walkB[9];
    sf::Texture attackR[13];
};
