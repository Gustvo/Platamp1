#include "mapping.h"


std::string** mapping(){
    std::string myString;

    const int width = 38;
    const int height = 20;
    static std::string** coord = new std::string*[width];
    for(int i = 0; i < width; ++i)
        coord[i] = new std::string[height];


    std::ifstream inFile("mapa2.csv");
    if(inFile.is_open()){
        int counter = 0;
        while(getline(inFile, myString, '\n')){
            std::stringstream stream(myString);
            for(int i = 0; i < 38; i++){
                getline(stream, coord[i][counter], ',');
                //if(coord[i][counter] == "44")
                  //  std::cout << i << " : " << counter << std::endl;
            }
        counter++;
        }
        inFile.close();
    }
    //cout << "Hello world!" << endl;
    return coord;
}
