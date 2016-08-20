#include "player.h"

Player::Player(){
    _moveSpeed = 3;
    _animationCounter = 0;
    int mSize = 60;
    //int spriteSize = 60;

    _coord = sf::Vector2f(50,770-mSize);
    //player texture
    if(!_tPlayer.loadFromFile("src\\NPC2.png")){
        std::cout << "ERROR";
    }

    //_tPlayer.setSmooth(true);
    _rect.setPosition(_coord);
    _rect.setSize(sf::Vector2f(mSize,mSize));
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
    else if(__direction == UP){
        _direction = __direction;
        _coord.y -= _moveSpeed/2;
    }
    else if(__direction == DOWN){
        _direction = __direction;
        _coord.y += _moveSpeed/2;
    }
//refresh rate
    if(frequency > 5){
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

sf::Vector2f Player::getSize(){
    return _rect.getSize();
}

DIRECTION Player::collision(sf::RectangleShape* object){
    if(_rect.getPosition().x + getSize().x >= object->getPosition().x - 2 &&
       _rect.getPosition().x + getSize().x <= object->getPosition().x + 2 &&
       _rect.getPosition().y + getSize().y <= object->getPosition().y -2 &&
       _rect.getPosition().y >= object->getPosition().y + object->getSize().y + 2){
            return RIGHT;
       }else if
       (_rect.getPosition().y + getSize().y >= object->getPosition().y -2 &&
        _rect.getPosition().y + getSize().y <= object->getPosition().y +2 &&
        _rect.getPosition().x + getSize().x <= object->getPosition().x &&
        _rect.getPosition().x >= object->getPosition().x + object->getSize().x){
            return DOWN;
        }
        else{
            return NO;
        }

}
