#include "game.h"

int width = 38; int height = 20;

sf::Texture tPlayer;
sf::Texture t103, t152, t68, t44, t40, t57, t45, t154, t32, t20;

JANELAS game(sf::RenderWindow* window){

    //window->setSize(sf::Vector2u(1000,600));
    //window->setPosition(sf::Vector2i(100,100));

    sf::View view(sf::Vector2f(500,469), sf::Vector2f(1000,700));


    ///Load Textures
    //Tiles textures
    if(!t152.loadFromFile("src\\Tiles\\grassCenter.png")){
        std::cout << "ERROR";
    }
    if(!t32.loadFromFile("src\\Tiles\\grassHillLeft.png")){
        std::cout << "ERROR";
    }
    if(!t20.loadFromFile("src\\Tiles\\grassHillLeft2.png")){
        std::cout << "ERROR";
    }
    if(!t154.loadFromFile("src\\Tiles\\stoneCenter.png")){
        std::cout << "ERROR";
    }
    if(!t40.loadFromFile("src\\Tiles\\signRight.png")){
        std::cout << "ERROR";
    }
    if(!t57.loadFromFile("src\\Tiles\\door_OpenMid.png")){
        std::cout << "ERROR";
    }
    if(!t45.loadFromFile("src\\Tiles\\door_OpenTop.png")){
        std::cout << "ERROR";
    }
    if(!t68.loadFromFile("src\\Tiles\\grassHalfLeft.png")){
        std::cout << "ERROR";
    }
    if(!t44.loadFromFile("src\\Tiles\\grassHalfRight.png")){
        std::cout << "ERROR";
    }
    if(!t103.loadFromFile("src\\Tiles\\grassMid.png")){
        std::cout << "ERROR";
    }

    //player texture
    if(!tPlayer.loadFromFile("src\\NPC2.png")){
        std::cout << "ERROR";
    }

    ///This creates a array to hold the coordinates of the level, together with the tile IDs
    std::string** coord = new std::string*[width];
    for(int i = 0; i < width; ++i)
        coord[i] = new std::string[height];

    coord = mapping(1);

    while(window->isOpen()){
        sf::Event event;
        while(window->pollEvent(event)){
            if(event.type == sf::Event::Closed){
                window->close();
            }
            //in case of keyboard pressing: Test if Escape to leave
            if(event.type == sf::Event::KeyPressed){
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
                    return MENU;
                }
            }
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
            view.move(sf::Vector2f(3,0));
        }

        window->setView(view);
        window->clear(sf::Color::White);

        printMap(coord, window);

        window->display();

    }
    delete coord;
    return MENU;
}

void printMap(std::string** _input, sf::RenderWindow* window){
    sf::RectangleShape _rect;
    _rect.setSize(sf::Vector2f(70,70));

    for(int x = 0; x<width; x++){
        for(int y = 0; y<height; y++){
            if(*(*(_input + x) + y) == "-1"){
                _rect.setPosition(sf::Vector2f(x*70, y*70));
                _rect.setTexture(NULL);
                _rect.setFillColor(sf::Color::Blue);
                window->draw(_rect);
            }
            else if(*(*(_input + x) + y) == "103"){
                _rect.setPosition(sf::Vector2f(x*70, y*70));
                _rect.setTexture(NULL);
                _rect.setFillColor(sf::Color::Blue);
                window->draw(_rect);

                _rect.setPosition(sf::Vector2f(x*70, y*70));
                _rect.setTexture(&t103,false);
                _rect.setFillColor(sf::Color::White);
                window->draw(_rect);
            }
            else if(*(*(_input + x) + y) == "152"){
                _rect.setPosition(sf::Vector2f(x*70, y*70));
                _rect.setTexture(NULL);
                _rect.setFillColor(sf::Color::Blue);
                window->draw(_rect);

                _rect.setPosition(sf::Vector2f(x*70, y*70));
                _rect.setTexture(&t152,false);
                _rect.setFillColor(sf::Color::White);
                window->draw(_rect);
            }
            else if(*(*(_input + x) + y) == "68"){
                _rect.setPosition(sf::Vector2f(x*70, y*70));
                _rect.setTexture(NULL);
                _rect.setFillColor(sf::Color::Blue);
                window->draw(_rect);

                _rect.setPosition(sf::Vector2f(x*70, y*70));
                _rect.setTexture(&t68,false);
                _rect.setFillColor(sf::Color::White);
                window->draw(_rect);
            }
            else if(*(*(_input + x) + y) == "44"){
                _rect.setPosition(sf::Vector2f(x*70, y*70));
                _rect.setTexture(NULL);
                _rect.setFillColor(sf::Color::Blue);
                window->draw(_rect);

                _rect.setPosition(sf::Vector2f(x*70, y*70));
                _rect.setTexture(&t44,false);
                _rect.setFillColor(sf::Color::White);
                window->draw(_rect);
            }
            else if(*(*(_input + x) + y) == "40"){
                _rect.setPosition(sf::Vector2f(x*70, y*70));
                _rect.setTexture(NULL);
                _rect.setFillColor(sf::Color::Blue);
                window->draw(_rect);

                _rect.setPosition(sf::Vector2f(x*70, y*70));
                _rect.setTexture(&t40,false);
                _rect.setFillColor(sf::Color::White);
                window->draw(_rect);
            }
            else if(*(*(_input + x) + y) == "57"){
                _rect.setPosition(sf::Vector2f(x*70, y*70));
                _rect.setTexture(NULL);
                _rect.setFillColor(sf::Color::Blue);
                window->draw(_rect);

                _rect.setPosition(sf::Vector2f(x*70, y*70));
                _rect.setTexture(&t57,false);
                _rect.setFillColor(sf::Color::White);
                window->draw(_rect);
            }
            else if(*(*(_input + x) + y) == "45"){
                _rect.setPosition(sf::Vector2f(x*70, y*70));
                _rect.setTexture(NULL);
                _rect.setFillColor(sf::Color::Blue);
                window->draw(_rect);

                _rect.setPosition(sf::Vector2f(x*70, y*70));
                _rect.setTexture(&t45,false);
                _rect.setFillColor(sf::Color::White);
                window->draw(_rect);
            }
            else if(*(*(_input + x) + y) == "154"){
                _rect.setPosition(sf::Vector2f(x*70, y*70));
                _rect.setTexture(NULL);
                _rect.setFillColor(sf::Color::Blue);
                window->draw(_rect);

                _rect.setPosition(sf::Vector2f(x*70, y*70));
                _rect.setTexture(&t154,false);
                _rect.setFillColor(sf::Color::White);
                window->draw(_rect);
            }
            else if(*(*(_input + x) + y) == "32"){
                _rect.setPosition(sf::Vector2f(x*70, y*70));
                _rect.setTexture(NULL);
                _rect.setFillColor(sf::Color::Blue);
                window->draw(_rect);

                _rect.setPosition(sf::Vector2f(x*70, y*70));
                _rect.setTexture(&t32,false);
                _rect.setFillColor(sf::Color::White);
                window->draw(_rect);
            }
            else if(*(*(_input + x) + y) == "20"){
                _rect.setPosition(sf::Vector2f(x*70, y*70));
                _rect.setTexture(NULL);
                _rect.setFillColor(sf::Color::Blue);
                window->draw(_rect);

                _rect.setPosition(sf::Vector2f(x*70, y*70));
                _rect.setTexture(&t20,false);
                _rect.setFillColor(sf::Color::White);
                window->draw(_rect);
            }
        }
    }

}
