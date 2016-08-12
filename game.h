#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include "Buttons.h"
#include "mapping.h"
#include "string"
#include <iostream>
#include <SFML/Graphics.hpp>

JANELAS game(sf::RenderWindow* window);

void printMap(std::string** _in, sf::RenderWindow* _window);


#endif // GAME_H_INCLUDED
