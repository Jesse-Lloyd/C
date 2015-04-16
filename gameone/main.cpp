/*
    Date last modified: 5th October 2012
    Developer: Jesse Lloyd
    Descritpion: a game i started developing for an assignment during my
    second year of study, so far the only things that are done are
    .animated charatecr movement using the W,S,A,D keys
    .a basic 3x3 world consisting of grass and road textures
    .an areachanger that detects when the player is at the edge of the screen
     and then loads the appropreate area of the world or stops the character
    .a random battle generator that once an integer is greater or lesser than a value
     then the battle area is loaded and displayed( no enemies yet )
*/
#include <SFML/Graphics.hpp>
#include "player.h"
#include "area.h"
#include "Battle.h"
//--------------------------Global attributes-------------------------------------------

//-------------------------------functions----------------------------------------------
int collisionDetection(sf::Sprite&,sf::Vector2f,int);
sf::Texture setFoliageTexture(int);
string setAreaTexture(int);
int battleEncounter(int);
void mouseClickPosition();
void BattleSystem(Battle*,sf::RenderWindow*,player*);
//--------------------------------------------------------------------------------------
int main()
{
    sf::RenderWindow window(sf::VideoMode(1280.0f, 600.0f), "SFML works!");
    window.setFramerateLimit(15);
    sf::Vector2f currentPosition;
    sf::Sprite areaBackDrop;
    sf::Clock battleTimer,coolDownTimer;
    player one;
    Battle beginBattle;
    area areas[10];
    sf::Sprite button[4];
    static int walkingNum=0,zone=4; //zone = starting area


    for(int i=0;i<=9;i++)
        areas[i].backDrop.loadFromFile(setAreaTexture(i));

    for(int i=0;i<4;i++)
        button[i].setTexture(beginBattle.loadButtonTexture(i));

    sf::Sprite character(one.loadSprite('z',0));
    character.setPosition(300.0f,500.0f);

   while (window.isOpen())
    {
        char key;
        sf::Event event;
        while (window.pollEvent(event))
        {
            currentPosition = character.getPosition();
            zone = collisionDetection(character,currentPosition,zone);
            if(zone !=9)
            {
                if(walkingNum == 8)
                    walkingNum =0;

                if(battleTimer.getElapsedTime().asSeconds() >= 7)
                {
                   battleTimer.restart();
                   if(coolDownTimer.getElapsedTime().asSeconds() >= 5)
                        zone = battleEncounter(zone);
                }

                if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) //move forward
                {
                    key = 'w';
                    if (one.timer.getElapsedTime().asMilliseconds() >= 90.0f)
                    {
                        character.setTexture(one.loadSprite(key,walkingNum));
                        one.timer.restart();
                        walkingNum = walkingNum +1;
                    }
                    character.move(0, -3.0f);
                }
                else
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) //move back
                {
                    key = 's';
                    if (one.timer.getElapsedTime().asMilliseconds() >= 90.0f)
                    {
                        character.setTexture(one.loadSprite(key,walkingNum));
                        one.timer.restart();
                        walkingNum = walkingNum +1;
                    }
                    character.move(0, 3.0f);
                }
                else
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) //move right
                {
                    key = 'd';
                    if (one.timer.getElapsedTime().asMilliseconds() >= 90.0f)
                    {
                        character.setTexture(one.loadSprite(key,walkingNum));
                        one.timer.restart();
                        walkingNum = walkingNum +1;
                    }
                    character.move(3.0f, 0);
                }
                else
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) //move left
                {
                    key = 'a';
                    if (one.timer.getElapsedTime().asMilliseconds() >= 90.0f)
                    {
                        character.setTexture(one.loadSprite(key,walkingNum));
                        one.timer.restart();
                        walkingNum = walkingNum +1;
                    }
                    character.move(-3.0f, 0);
                }
            }
            else
            {
                //BattleSystem(&beginBattle,&window,&one);
                character.setTexture(one.loadSprite('A',0));
                character.setPosition(250.0f,450.0f);
            }
            if (event.type == sf::Event::Closed)    //close window
                window.close();

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))//close window
                window.close();
        }
            window.clear();
            areaBackDrop.setTexture(areas[zone].backDrop);
            window.draw(areaBackDrop);
            window.draw(character);
            if(zone == 9)
            {
                for(int i=0;i<4;i++)    //set the pos and draw the buttons for the battle system
                {
                    button[i].setPosition(i*145,575.0f);
                    window.draw(button[i]);
                }
            }
            window.display();
    }
    return 0;
}
