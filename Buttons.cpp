#include "Buttons.h"


Button::Button() {
	//setTexture(sf::Color::Black);
	setPos(sf::Vector2f(0,0));
	setSize(sf::Vector2f(50,50));
}
Button::Button(sf::Vector2f __pos, sf::Vector2f __size, sf::Texture* __texture) {
	setSize(__size);
	setPos(__pos);
	setTexture(__texture, sf::IntRect(0,0,20,20));
	//sprite.setPosition(_rect.getPosition());
}

void Button::setSize(sf::Vector2f __size) {
	_rect.setSize(__size);
}

void Button::setTexture(sf::Texture* __texture, sf::IntRect __IntRect) {
	_rect.setTexture(__texture, false);
	_rect.setTextureRect(__IntRect);

}

void Button::setPos(sf::Vector2f __pos) {
	_rect.setPosition(__pos);
}

sf::Vector2f Button::getPos() {
	return _rect.getPosition();
}

sf::Vector2f Button::getSize() {
	return _rect.getSize();
}

sf::Color Button::getColor() {
	return _rect.getFillColor();
}

void Button::draw(sf::RenderWindow* window) {
	window->draw(_rect);
}

bool Button::isPressed(sf::Vector2i __mousePos) {
	if((__mousePos.x >= getPos().x && __mousePos.y >= getPos().y) && (__mousePos.x <= getPos().x + getSize().x &&
        __mousePos.y <= getPos().y + getSize().y))
            return true;
    return false;
}
