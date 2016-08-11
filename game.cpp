#include "game.h"

JANELAS game(sf::RenderWindow* window){

    sf::Texture t103, t152, t68, t44, t40, t57, t45, t154, t32, t20;

    if(!t152.loadFromFile("Tiles\\grassCenter.png")){
        std::cout << "ERROR";
    }
    if(!t32.loadFromFile("Tiles\\grassHillLeft.png")){
        std::cout << "ERROR";
    }
    if(!t20.loadFromFile("Tiles\\grassHillLeft2.png")){
        std::cout << "ERROR";
    }
    if(!t154.loadFromFile("Tiles\\stoneCenter.png")){
        std::cout << "ERROR";
    }
    if(!t40.loadFromFile("Tiles\\signRight.png")){
        std::cout << "ERROR";
    }
    if(!t57.loadFromFile("Tiles\\door_OpenMid.png")){
        std::cout << "ERROR";
    }
    if(!t45.loadFromFile("Tiles\\door_OpenTop.png")){
        std::cout << "ERROR";
    }
    if(!t68.loadFromFile("Tiles\\grassHalfLeft.png")){
        std::cout << "ERROR";
    }
    if(!t44.loadFromFile("Tiles\\grassHalfRight.png")){
        std::cout << "ERROR";
    }
    if(!t103.loadFromFile("Tiles\\grassMid.png")){
        std::cout << "ERROR";
    }
    if(!tplayer.loadFromFile("NPC2.png")){
        std::cout << "ERROR";
    }


    return MENU;
}
