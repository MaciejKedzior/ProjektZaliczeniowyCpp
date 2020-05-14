#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include <fstream>
#include "functions.h"


Card::Card (std::string _name, std::string _type): name{_name}, type{_type} {}
Card::~Card(){ std::cout<<""; }
std::string Card::getName() const {return name;}
std::string Card::getType() const {return type;}

Przywodca::Przywodca (std::string _name): Card{_name, "Przywodca"} {}
Przywodca::~Przywodca (){ std::cout<<"Zniszczono karte"<<std::endl; };
void Przywodca::showInfo(){
    std::cout<<this->getName()<<":"<<std::endl;
    std::cout<<"Typ karty: Przywodca"<<std::endl<<std::endl;
}

BliskieStarcie::BliskieStarcie(std::string _name, int _points): Card{_name, "Bliskie starcie"}, points{_points} {}
BliskieStarcie::~BliskieStarcie(){ std::cout<<"Zniszczono karte"<<std::endl; };
int BliskieStarcie::getPoints() const { return points; } 
void BliskieStarcie::showInfo(){
    std::cout<<this->getName()<<":"<<std::endl;
    std::cout<<"Typ karty: Bliskie starcie"<<std::endl;
    std::cout<<"Liczba punktow: "<<this->getPoints()<<std::endl<<std::endl;
}

DalekiZasieg::DalekiZasieg(std::string _name, int _points): Card{_name, "Daleki zasieg"}, points{_points} {}
DalekiZasieg::~DalekiZasieg(){ std::cout<<"Zniszczono karte"<<std::endl; };
int DalekiZasieg::getPoints() const { return points; } 
void DalekiZasieg::showInfo(){
    std::cout<<this->getName()<<":"<<std::endl;
    std::cout<<"Typ karty: Daleki zasieg"<<std::endl;
    std::cout<<"Liczba punktow: "<<this->getPoints()<<std::endl<<std::endl;
}

JednostkaObl::JednostkaObl(std::string _name, int _points): Card{_name, "Jednostka obleznicza"}, points{_points} {}
JednostkaObl::~JednostkaObl(){ std::cout<<"Zniszczono karte"<<std::endl; };
int JednostkaObl::getPoints() const { return points; } 
void JednostkaObl::showInfo(){
    std::cout<<this->getName()<<":"<<std::endl;
    std::cout<<"Typ karty: Jednostka obleznicza"<<std::endl;
    std::cout<<"Liczba punktow: "<<this->getPoints()<<std::endl<<std::endl;
}


Card* createObject(std::vector <std::string> array){
    std::string name = array.at(0);
    std::string type = array.at(1);
    int points = std::stoi(array.at(2));
    
    Card *temp;

    typedef std::vector<std:: string> StringContainer;
    typedef StringContainer::iterator StringIterator;
    std::vector <std::string> vec = {"Przywodca", "BliskieStarcie", 
                                    "DalekiZasieg", "JednostkaObl"};
    
    StringIterator position = std::find(vec.begin(), vec.end(), type);
    int index = std::distance(vec.begin(), position);

    
    try{
        if (!vec.at(index).compare("Przywodca")) temp = new Przywodca(name);
        else if (!vec.at(index).compare("BliskieStarcie")) temp = new BliskieStarcie(name, points);
        else if (!vec.at(index).compare("DalekiZasieg")) temp = new DalekiZasieg(name, points);
        else if (!vec.at(index).compare("JednostkaObl")) temp = new JednostkaObl(name, points);
    }
    catch (std::out_of_range& e){ 
        throw std::out_of_range("Nie mozna odnalezc typu karty w wektorze typow!\n");
    } 
    return temp;
}

