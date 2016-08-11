#include "Buttons.h"
#include "menu.h"

#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>

///Configura��o da Janela
int wWidth = 600; //Largura da Janela em pixels
int wHeight = 600;  //Altura da Janela em pixels
std::string wName = "Minha Janela"; //T�tulo da Janela

///Criando texturas
const int nMenu_Texture = 2;//quantidade de texturas no MENU

sf::Texture menu_texture[nMenu_Texture];


int main(){

    JANELAS janela = MENU;
    sf::RenderWindow window(sf::VideoMode(wWidth,wHeight), wName, sf::Style::Close);
    window.setFramerateLimit(30);

    while(window.isOpen()){
        sf::Event event;

        while(window.pollEvent(event)){
            if(event.type == sf::Event::Closed){
                window.close();
            }
            else if(event.type == sf::Event::KeyPressed){
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                    window.close();
            }
            /*else if(event.type == sf::Event::MouseButtonPressed){
                if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
                    std::cout << mPos.x << " " << mPos.y << std::endl;
            }*/
        }

        window.clear(sf::Color::Black);

        if(janela == MENU){
            janela = menu(&window);
        }
        else if(janela == SAVE){
            //janela =
        }
        else if(janela == LOAD){

        }
        else if(janela == GAME){

        }
        else if(janela == ERROR){
            std::cout << "ERROR";
            return 0;
        }

    }


    return 0;
}
