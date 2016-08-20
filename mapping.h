#ifndef MAPPING_H_INCLUDED
#define MAPPING_H_INCLUDED

#include <fstream>
#include <string>
#include <sstream>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>

std::string** mapping(int);

void drawSprite(sf::Texture* _texture, sf::Vector2f _coord, sf::RenderWindow* _window, sf::RectangleShape* _rect);
void drawSprite(sf::Vector2f _coord, sf::RenderWindow* _window);

#endif // MAPPING_H_INCLUDED
