#include "mapping.h"

int spriteHeight = 70;
int spriteWidth = 70;

std::string** mapping(int mapa){
    std::string myString;

    const int width = 38;
    const int height = 20;
    static std::string** coord = new std::string*[width];
    for(int i = 0; i < width; ++i)
        coord[i] = new std::string[height];


    std::ifstream inFile("src\\mapa1.csv");
    if(inFile.is_open()){
        int counter = 0;
        while(getline(inFile, myString, '\n')){
            std::stringstream stream(myString);
            for(int i = 0; i < width; i++){
                getline(stream, coord[i][counter], ',');
                //if(coord[i][counter] == "44")
                  //  std::cout << i << " : " << counter << std::endl;
            }
        counter++;
        }
        inFile.close();
    }
    //cout << "Hello world!" << endl;
    return coord;
}
void drawRect(sf::Texture* _texture, sf::Vector2f _coord, sf::RenderWindow* _window){

    sf::RectangleShape _rect;
    _rect.setSize(sf::Vector2f(spriteWidth,spriteHeight));

    _rect.setPosition(_coord.x * spriteWidth, _coord.y * spriteHeight);
    _rect.setTexture(NULL);
    _rect.setFillColor(sf::Color::Blue);
    _window->draw(_rect);

    _rect.setTexture(_texture);
    _rect.setFillColor(sf::Color::White);
    _window->draw(_rect);
}
void drawRect(sf::Vector2f _coord, sf::RenderWindow* _window){
    sf::RectangleShape _rect;
    _rect.setSize(sf::Vector2f(spriteWidth,spriteHeight));

    _rect.setPosition(_coord.x * spriteWidth, _coord.y * spriteHeight);
    _rect.setTexture(NULL);
    _rect.setFillColor(sf::Color::Blue);
    _window->draw(_rect);
}
