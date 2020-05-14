#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include "functions.h"

int main(void){
    std::string wiersz;
    std::vector <std::vector <std::string>> testy;
    std::vector <Card*> obiekty;
    std::ifstream plik;
    
    plik.open("dane.txt");

    if(!plik.good()){
        std::cout<<"not good :<\n";
        exit(EXIT_FAILURE);
    }

    while (getline(plik, wiersz)){
        testy.push_back(splitString(wiersz, ";"));
    }
    
    for (auto& i: testy)
        obiekty.push_back(createObject(i));


    for (auto& i: obiekty) i->showInfo();
    for (auto& i: obiekty) delete i;
    return 0;
}
