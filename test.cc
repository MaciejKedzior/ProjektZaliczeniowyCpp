#include <iostream>
#include <string>
#include "window.hpp"
#include <vector>
#include <fstream>
#include <string>


std::vector <Card <int>*> loadObjects(const std::string& file_name){
    std::string wiersz;
    std::vector <std::vector <std::string>> testy;
    std::vector <Card <int>*> obiekty;
    std::ifstream plik;
    
    plik.open(file_name);

    if(!plik.good()){
        std::cout<<"not good :<\n";
        exit(EXIT_FAILURE);
    }

    while (getline(plik, wiersz)){
        testy.push_back(splitString(wiersz, ";"));
    }
    
    for (auto& i: testy)
        obiekty.emplace_back(createObject<int>(i));
    
    return obiekty;
}


int main(){
    std::vector <Card<int>*> objects = loadObjects("dane_wejsciowe");
    for (auto& z: objects) std::cout<<z->getDetails()<<std::endl;

    Window menu("Font/arial.ttf", objects);
    menu.run(objects);

    return 0;
}
