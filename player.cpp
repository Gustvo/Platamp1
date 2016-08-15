#include "player.h"

Player::Player(){
    _moveSpeed = 3;
    _animationCounter = 0;

    _coord = sf::Vector2f(50,770-40);
    //player texture
    if(!_tPlayer.loadFromFile("src\\NPC2.png")){
        std::cout << "ERROR";
    }
    //_tPlayer.setSmooth(true);
    _rect.setPosition(_coord);
    _rect.setSize(sf::Vector2f(40,40));
    _rect.setTexture(&_tPlayer);
    _rect.setTextureRect(sf::IntRect(128+32*3,96,32,32));
}

void Player::draw(sf::RenderWindow* _window){
    _window->draw(_rect);
    if(_direction == RIGHT)
        _rect.setTextureRect(sf::IntRect(128+32*3,96,32,32));
    else if(_direction == LEFT)
        _rect.setTextureRect(sf::IntRect(0+32*3,96,32,32));
}

void Player::move(DIRECTION __direction){
    static int frequency = 0;
    if(__direction == RIGHT){
        _direction = __direction;
        _coord.x += _moveSpeed;
        frequency++;
    }
    else if(__direction == LEFT){
        _direction = __direction;
        _coord.x -= _moveSpeed;
        frequency++;
    }
//refresh rate
    if(frequency > 4){
        frequency = 0;
        _animationCounter++;
    }


    if(_animationCounter > 3){
        _animationCounter = 0;
    }
    _rect.setPosition(_coord);
    if(_direction == RIGHT)
        _rect.setTextureRect(sf::IntRect(128+32*(3-_animationCounter), 96, 32, 32));
    else if(_direction == LEFT)
        _rect.setTextureRect(sf::IntRect(0+32*(3-_animationCounter), 96, 32, 32));
}

sf::Vector2f Player::getPosition(){
    return _rect.getPosition();
}
