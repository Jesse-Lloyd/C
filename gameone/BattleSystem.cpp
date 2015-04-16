#include <SFML/Graphics.hpp>
#include <iostream>
#include "Battle.h"
#include "player.h"
#include "enemy.h"

using namespace std;
//---------------------------------functions---------------------------------------------------
void mouseClickPosition();
//---------------------------------------------------------------------------------------------
void BattleSystem(Battle *beginBattle,sf::Window *window, player *one)
{
    enemy foe;
    sf::Sprite enemy,character;

    while(beginBattle->finished == false)
    {
        cout <<"hitter";
         character.setTexture(one->loadSprite('A',0));
                character.setPosition(250.0f,450.0f);
                float speedOfTimer = one->getStats();
                if(beginBattle->turnTimer.getElapsedTime().asSeconds() >= 35/speedOfTimer)
                    if(sf::Mouse::isButtonPressed(sf::Mouse::Left))                             //get the current pos of the mouse when the mouse button is pressed after the turnTimer reaches a certain amount
                       if(sf::Mouse::getPosition().y <=710 && sf::Mouse::getPosition().y >= 695)
                       {
                          mouseClickPosition();
                          beginBattle->turnTimer.restart();
                       }
    }
}
void mouseClickPosition()
{

    if(sf::Mouse::getPosition().x <=980 && sf::Mouse::getPosition().x >=930)   //retreat
        cout<<"retreat";
    else
    if(sf::Mouse::getPosition().x <=900 && sf::Mouse::getPosition().x >=858)    //rest
        cout<<"rest";
    else
    if(sf::Mouse::getPosition().x <=825  && sf::Mouse::getPosition().x >=780)   // defend
        cout<<"defend";
    else
    if(sf::Mouse::getPosition().x <=753 && sf::Mouse::getPosition().x >=703)    //attack
        cout<<"attack";
}
void choseEnemy()
{


}
