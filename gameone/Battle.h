#include <SFML/Graphics.hpp>
#include <sstream>
#include <string>


using namespace std;
//-------------------------------
class Battle
{
    public:
    Battle(){setButtonTextures();};
    ~Battle(){};

    sf::Clock turnTimer;
    sf::Texture& loadButtonTexture(int);
    bool finished;

    private:
    void setButtonTextures();
    sf::Texture turnTimerImg;
    sf::Texture buttons[5];
};
