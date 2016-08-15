#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include <SFML/Graphics.hpp>
#include <iostream>

enum DIRECTION{UP, DOWN, LEFT, RIGHT};

class Player {
    sf::Vector2f _coord;
    sf::RectangleShape _rect;
    sf::Texture _tPlayer;
    int _moveSpeed;
    int _animationCounter;
    DIRECTION _direction;
public:

    DIRECTION collision(sf::RectangleShape);
    void move(DIRECTION);
    Player();
    void draw(sf::RenderWindow*);
    sf::Vector2f getPosition();

};

#endif // PLAYER_H_INCLUDED
