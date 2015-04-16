#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");
    //sf::Text text("HMMMMM not bad");
    sf::Texture texture;
    sf::Texture screenshot;
    sf::Image temp;
    if (!texture.loadFromFile("2832.jpg"))
         return EXIT_FAILURE;

//-------------------------SPRITE'S---------------------------
    sf::Sprite Sprite(texture);
    /*Sprite.setPosition(100.0f, 30.0f);
    Sprite.setRotation(30.0f);
    Sprite.setScale(.6f, .8f);
    Sprite.setColor(sf::Color(255, 0, 0, 128));*/
//------------------------------------------------------------

    while (window.isOpen())
    {

         sf::Event event;
         temp = window.capture();
         while (window.pollEvent(event))
         {
             // Close window : exit
            if (event.type == sf::Event::Closed)
                window.close();


         }

            window.clear();
            window.draw(Sprite);
            window.display();



    }
    temp.saveToFile("temp.jpg");

    /*while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(text);
        window.display();
    }*/

    return 0;
}
