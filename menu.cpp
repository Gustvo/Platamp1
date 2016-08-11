#include "menu.h"

const int nBut = 2;

Button buttons[nBut];

JANELAS menu(sf::RenderWindow* window) {

    int i_MenuY = 50;
    int spacing = 20;

    sf::Texture texture[2];
    sf::Texture backgroundTexture;

    if(!backgroundTexture.loadFromFile("src\\Background.jpg")){
        return ERROR;
    }
    if(!texture[0].loadFromFile("src\\Menu.png")){// Texture for background
        return ERROR;
    }

    sf::RectangleShape background;
    background.setSize(sf::Vector2f(window->getSize()));
    background.setTexture(&backgroundTexture, false);

    buttons[0].setPos(sf::Vector2f(window->getSize().x/2-100, spacing+(spacing + 50)*0));
    buttons[0].setSize(sf::Vector2f(200,50));
    buttons[0].setTexture(&texture[0], sf::IntRect(0, i_MenuY * 0, 200, i_MenuY*1));

    buttons[1].setPos(sf::Vector2f(window->getSize().x/2-100, spacing+(spacing + 50)*1));
    buttons[1].setSize(sf::Vector2f(200,50));
    buttons[1].setTexture(&texture[0], sf::IntRect(0, 60, 200,50));

    /*if(!texture[1].loadFromFile("src\\menu.png")){// Texture for Menu Buttons
        return ERROR;
    }*/



    while(window->isOpen()){
        sf::Event event;
        sf::Vector2i mPos = sf::Mouse::getPosition(*window);
        while(window->pollEvent(event)){
            if(event.type == sf::Event::Closed){
                window->close();
            }
            else if(event.type == sf::Event::KeyPressed){
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
                    sf::RenderWindow * areYouSure = new sf::RenderWindow(sf::VideoMode(300,200),
                                                                         "Are you sure you wanna leave?",
                                                                         sf::Style::Close);

                    sf::Font* arial = new sf::Font;
                    if(!arial->loadFromFile("src\\ARIAL.TTF"))
                        return ERROR;

                    sf::Text* text = new sf::Text("Wanna Leave? \n(press ENTER to leave)", *arial, 20);
                    text->setPosition(sf::Vector2f(20,20));

                    while(areYouSure->isOpen()){
                        sf::Event choice;
                        while(areYouSure->pollEvent(choice)){
                            if(choice.type == sf::Event::KeyPressed){
                                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Return)){
                                    areYouSure->close();
                                    window->close();
                                }
                                else{
                                    areYouSure->close();
                                }
                            }
                            if(choice.type == sf::Event::Resized){

                            }
                        }
                        areYouSure->requestFocus();
                        areYouSure->clear();
                        areYouSure->draw(*text);
                        areYouSure->display();
                    }
                    delete areYouSure;
                    delete text;
                    delete arial;
                }
            }
            else if(event.type == sf::Event::MouseButtonPressed){
                if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                    if(buttons[0].isPressed(mPos)) // Se "New Game" for pressionado
                        return GAME;

                    if(buttons[1].isPressed(mPos)) // Se "Load" for pressionado
                        return LOAD;
                }
            }
        }
        window->clear();
        window->draw(background);

        for(int i = 0; i < nBut; i++)
        {
            buttons[i].draw(window);
        }

        window->display();
    }
    return MENU;
}
