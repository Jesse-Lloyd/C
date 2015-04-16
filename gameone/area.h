#include <SFML/Graphics.hpp>
//--------------------------
class area
{
    public:
    area(){}
    ~area(){}
    sf::Texture backDrop;

    private:
    int xAxis[1300];
    int yAxis[700];

    void setFoliage();
};
