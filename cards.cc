#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#include "functions.h"


Card::Card (std::string _name, std::string _type, int _points, std::string file_name): 
name{_name}, type{_type}, points{_points}
{
    if(!texture.loadFromFile(file_name)){
        std::cout<<"Error loading file\n";
        exit(EXIT_FAILURE);
    }
    texture.setSmooth(true);
    texture.setRepeated(true);

    sprite.setTexture(texture);
    sprite.setPosition(0.f, 0.f);
}

Card::~Card(){ std::cout<<""; }

std::string Card::getName() const {return name;}

std::string Card::getType() const {return type;}

int Card::getPoints() const {return points;}

sf::Sprite Card::getGraphics() const {return sprite;}



Przywodca::Przywodca (std::string _name, std::string file_name): 
Card{_name, "Przywodca", 0, file_name} {}

Przywodca::~Przywodca (){ std::cout<<"Zniszczono karte"<<std::endl; };

void Przywodca::showInfo(){
    std::cout<<this->getName()<<":"<<std::endl;
    std::cout<<"Typ karty: Przywodca"<<std::endl<<std::endl;
}
/*
std::vector <sf::Text> Przywodca::getValues(){
    std::vector <sf::Text> temp;
    std::stringstream ss, so;
    sf::Text name, details;

    ss << "Nazwa karty: " << this->getName();
    name.setString(ss.str());
    temp.push_back(name);

    so << "Opis przywódcy: ";
    
    return temp;

}*/


BliskieStarcie::BliskieStarcie(std::string _name, int _points, std::string file_name): 
Card{_name, "Bliskie starcie", _points, file_name} {}

BliskieStarcie::~BliskieStarcie(){ std::cout<<"Zniszczono karte"<<std::endl; };

int BliskieStarcie::getPoints() const { return points; } 

void BliskieStarcie::showInfo(){
    std::cout<<this->getName()<<":"<<std::endl;
    std::cout<<"Typ karty: Bliskie starcie"<<std::endl;
    std::cout<<"Liczba punktow: "<<this->getPoints()<<std::endl<<std::endl;
}




DalekiZasieg::DalekiZasieg(std::string _name, int _points, std::string file_name): 
Card{_name, "Daleki zasieg", _points, file_name} {}

DalekiZasieg::~DalekiZasieg(){ std::cout<<"Zniszczono karte"<<std::endl; };

int DalekiZasieg::getPoints() const { return points; } 

void DalekiZasieg::showInfo(){
    std::cout<<this->getName()<<":"<<std::endl;
    std::cout<<"Typ karty: Daleki zasieg"<<std::endl;
    std::cout<<"Liczba punktow: "<<this->getPoints()<<std::endl<<std::endl;
}



JednostkaObl::JednostkaObl(std::string _name, int _points, std::string file_name): 
Card{_name, "Jednostka obleznicza", _points, file_name} {}

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
    std::string filename = array.at(3);
    Card *temp;

    typedef std::vector<std:: string> StringContainer;
    typedef StringContainer::iterator StringIterator;
    std::vector <std::string> vec = {"Przywodca", "BliskieStarcie", 
                                    "DalekiZasieg", "JednostkaObl"};
    
    StringIterator position = std::find(vec.begin(), vec.end(), type);
    int index = std::distance(vec.begin(), position);

    
    try{
        if (!vec.at(index).compare("Przywodca")) temp = new Przywodca(name, filename);
        else if (!vec.at(index).compare("BliskieStarcie")) temp = new BliskieStarcie(name, points, filename);
        else if (!vec.at(index).compare("DalekiZasieg")) temp = new DalekiZasieg(name, points, filename);
        else if (!vec.at(index).compare("JednostkaObl")) temp = new JednostkaObl(name, points, filename);
    }
    catch (std::out_of_range& e){ 
        throw std::out_of_range("Nie mozna odnalezc typu karty w wektorze typow!\n");
    } 
    return temp;
}

