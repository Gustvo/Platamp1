#ifndef MAPPING_H_INCLUDED
#define MAPPING_H_INCLUDED

#include <fstream>
#include <string>
#include <sstream>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>

std::string** mapping(int);

void drawRect(sf::Texture* _texture, sf::Vector2f _coord, sf::RenderWindow* _window);
void drawRect(sf::Vector2f _coord, sf::RenderWindow* _window);

#endif // MAPPING_H_INCLUDED
