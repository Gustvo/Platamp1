#include "mapping.h"

//sprite size - defined by sprite sheet
int spriteHeight = 70;
int spriteWidth = 70;

int mapWidth, mapHeight; //both HAVE to be on the first line of the csv file

std::string** mapping(int mapa){
    std::string myString;


    ///HAVE TO CHANGE DIS!
    const int width = 300; //map max size
    const int height = 300; //map max size
    static std::string** coord = new std::string*[width];
    for(int i = 0; i < width; ++i)
        coord[i] = new std::string[height];


    //loads map csv file, add it as variable?
    std::ifstream inFile("src\\mapa1.csv");
    if(inFile.is_open()){
        int y = 0;
        if(y == 0){
                inFile >> mapWidth >> mapHeight;
                getline(inFile, myString, '\n');
                std::cout << mapWidth << " " << mapHeight;
                //break;
                y++;
        }
        while(getline(inFile, myString, '\n')){

            std::stringstream stream(myString);

            int x = 0;
            while(getline(stream, coord[x][y], ',')){
                x++;
            }
            x=0;
            y++;
        }
        inFile.close();
    }
    //cout << "Hello world!" << endl;
    return coord;
}
void drawSprite(sf::Texture* _texture, sf::Vector2f _coord, sf::RenderWindow* _window, sf::RectangleShape* _rect){

    //sf::RectangleShape _rect;
    _rect->setSize(sf::Vector2f(spriteWidth,spriteHeight));

    _rect->setPosition(_coord.x * spriteWidth, _coord.y * spriteHeight);
    _rect->setTexture(NULL);
    _rect->setFillColor(sf::Color::Blue);
    _window->draw(*_rect);

    _rect->setTexture(_texture);
    _rect->setFillColor(sf::Color::White);
    _window->draw(*_rect);
}
void drawSprite(sf::Vector2f _coord, sf::RenderWindow* _window){
    sf::RectangleShape _rect;
    _rect.setSize(sf::Vector2f(spriteWidth,spriteHeight));

    _rect.setPosition(_coord.x * spriteWidth, _coord.y * spriteHeight);
    _rect.setTexture(NULL);
    _rect.setFillColor(sf::Color::Blue);
    _window->draw(_rect);
}
