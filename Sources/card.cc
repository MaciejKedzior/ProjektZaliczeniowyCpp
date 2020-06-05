#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#include "card.hpp"


Card::Card (std::string _name, std::string _type, std::string _details, int _points, std::string file_name): 
name{_name}, details{fix_newlines(_details)}, type{_type}, points{_points}
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

Card::Card (const Card& card):
name{card.getName()}, details{card.getDetails()}, type{card.getType()}, points{card.getPoints()},
sprite{card.getGraphics()} {}


Card::~Card(){ std::cout<<"finito"; }

std::string Card::getName() const {return name;}

std::string Card::getType() const {return type;}

std::string Card::getDetails() const { return details; }

int Card::getPoints() const {return points;}

sf::Sprite Card::getGraphics() const {return sprite;}

void Card::setPoints(int value) { points = value;}



Przywodca::Przywodca (std::string _name, std::string details, std::string file_name): 
Card{_name, "Przywodca", details, 0, file_name} {}

Przywodca:: Przywodca(const Card& przywodca): Card{przywodca} {}
void Przywodca::showInfo(){
    std::cout<<this->getName()<<":"<<std::endl;
    std::cout<<"Typ karty: Przywodca"<<std::endl<<std::endl;
}

std::vector <sf::Text> Przywodca::getValues(){
    std::vector <sf::Text> temp;
    std::stringstream ss, so;
    sf::Text name, points, details;

    ss << "Nazwa karty: " << this->getName();
    name.setString(ss.str());
    temp.push_back(name);

    points.setString("Przywodca nie posiada punktow");
    temp.push_back(points);

    so << "Opis przywodcy:\n" << this->getDetails();
    details.setString(so.str());
    temp.push_back(details);
    
    return temp;

}


BliskieStarcie::BliskieStarcie(std::string _name, std::string _details, int _points, std::string file_name): 
Card{_name, "Bliskie starcie", _details, _points, file_name} {}
BliskieStarcie:: BliskieStarcie(const Card& bliskie): Card{bliskie} {}


void BliskieStarcie::showInfo(){
    std::cout<<this->getName()<<":"<<std::endl;
    std::cout<<"Typ karty: Bliskie starcie"<<std::endl;
    std::cout<<"Liczba punktow: "<<this->getPoints()<<std::endl<<std::endl;
}

std::vector <sf::Text> BliskieStarcie::getValues(){
    std::vector <sf::Text> temp;
    std::stringstream ss, so, sp;
    sf::Text name, details, points;

    ss << "Nazwa karty: " << this->getName();
    name.setString(ss.str());
    temp.push_back(name);

    sp << "Liczba punktow: " << std::to_string(this->getPoints());
    points.setString(sp.str());
    temp.push_back(points);

    so << "Opis karty:\n" << this->getDetails();
    details.setString(so.str());
    temp.push_back(details);
    
    return temp;

}



DalekiZasieg::DalekiZasieg(std::string _name, std::string _details, int _points, std::string file_name): 
Card{_name, "Daleki zasieg", _details, _points, file_name} {}

DalekiZasieg:: DalekiZasieg(const Card& daleki): Card(daleki){}

void DalekiZasieg::showInfo(){
    std::cout<<this->getName()<<":"<<std::endl;
    std::cout<<"Typ karty: Daleki zasieg"<<std::endl;
    std::cout<<"Liczba punktow: "<<this->getPoints()<<std::endl<<std::endl;
}

std::vector <sf::Text> DalekiZasieg::getValues(){
    std::vector <sf::Text> temp;
    std::stringstream ss, so, sp;
    sf::Text name, details, points;

    ss << "Nazwa karty: " << this->getName();
    name.setString(ss.str());
    temp.push_back(name);
    
    sp << "Liczba punktow: " << std::to_string(this->getPoints());
    points.setString(sp.str());
    temp.push_back(points);

    so << "Opis karty:\n" << this->getDetails();
    details.setString(so.str());
    temp.push_back(details);
    
    return temp;

}

JednostkaObl::JednostkaObl(std::string _name, std::string _details, int _points, std::string file_name): 
Card{_name, "Jednostka obleznicza", _details, _points, file_name} {}

JednostkaObl::JednostkaObl(const Card& jednostka): Card{jednostka} {}

//int JednostkaObl::getPoints() const { return points; } 

void JednostkaObl::showInfo(){
    std::cout<<this->getName()<<":"<<std::endl;
    std::cout<<"Typ karty: Jednostka obleznicza"<<std::endl;
    std::cout<<"Liczba punktow: "<<this->getPoints()<<std::endl<<std::endl;
}

std::vector <sf::Text> JednostkaObl::getValues(){
    std::vector <sf::Text> temp;
    std::stringstream ss, so, sp;
    sf::Text name, details, points;

    ss << "Nazwa karty: " << this->getName();
    name.setString(ss.str());
    temp.push_back(name);

    sp << "Liczba punktow: " << std::to_string(this->getPoints());
    points.setString(sp.str());
    temp.push_back(points);

    so << "Opis karty:\n" << this->getDetails();
    details.setString(so.str());
    temp.push_back(details);
    
    return temp;

}


Card* createObject(std::vector <std::string> array){
    std::string name = array.at(0);
    std::string type = array.at(1);
    std::string details = array.at(2);
    int points = std::stoi(array.at(3));
    std::string filename = array.at(4);
    Card *temp;

    typedef std::vector<std:: string> StringContainer;
    typedef StringContainer::iterator StringIterator;
    std::vector <std::string> vec = {"Przywodca", "BliskieStarcie", 
                                    "DalekiZasieg", "JednostkaObl"};
    
    StringIterator position = std::find(vec.begin(), vec.end(), type);
    int index = std::distance(vec.begin(), position);
    
    try{
        if (!vec.at(index).compare("Przywodca")) temp = new Przywodca(name, details, filename);
        else if (!vec.at(index).compare("BliskieStarcie")) temp = new BliskieStarcie(name, details, points, filename);
        else if (!vec.at(index).compare("DalekiZasieg")) temp = new DalekiZasieg(name, details, points, filename);
        else if (!vec.at(index).compare("JednostkaObl")) temp =  new JednostkaObl(name, details, points, filename);
    }
    catch (std::out_of_range& e){ 
        throw std::out_of_range("Nie mozna odnalezc typu karty w wektorze typow!\n");
    }
    return temp;
}

