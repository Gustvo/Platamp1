#ifndef BUTTONS_H_INCLUDED
#define BUTTONS_H_INCLUDED

#include <SFML/Graphics.hpp>

enum JANELAS {MENU, SAVE, GAME, LOAD, ERROR};

class Button {

	sf::RectangleShape _rect;


public:
    Button(sf::Vector2f __pos, sf::Vector2f __size, sf::Texture* texture);
    Button();

    void setPos(sf::Vector2f);
    void setSize(sf::Vector2f);
    void setTexture(sf::Texture* , sf::IntRect);

    sf::Vector2f getPos();
    sf::Vector2f getSize();
    sf::Color getColor();
    //sf::Sprite sprite;

    bool isPressed(sf::Vector2i);

    void draw(sf::RenderWindow*);

};

#endif // BUTTONS_H_INCLUDED
