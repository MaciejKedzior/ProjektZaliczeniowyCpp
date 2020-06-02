#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>


// INTERFEJS KLAS
template <class T>
class Card{     
    public:
        Card (std::string _name, std::string _type, std::string _details, T _points, std::string file_name);
        Card (const Card<T> &card);
        Card& operator=(const Card<T>&) {return *this;};
        virtual void showInfo()=0;
        virtual std::vector<sf::Text> getValues()=0;
        std::string getName() const;
        std::string getType() const;
        std::string getDetails() const;
        T getPoints() const;
        sf::Sprite getGraphics() const;
        void setPoints(T value);
        virtual ~Card()=0;
    private:
        std::string details;
        sf::Texture texture;
        std::string name;
        std::string type;
        T points;
        sf::Sprite sprite;
};

template <class T>
class Przywodca:public Card<T>{
    public:
        Przywodca (std::string _name, std::string _details, std::string file_name);
        Przywodca& operator=(const Przywodca<T>&) {return *this;};
        Przywodca (const Card<T>& przywodca);
        ~Przywodca () { std::cout<<"Zniszczono karte"<<std::endl; };
        void showInfo(); 
        std::vector<sf::Text> getValues();
};

template <class T>
class BliskieStarcie:public Card<T>{
    public:
        BliskieStarcie(std::string _name, std::string _details, T _points, std::string file_name);
        BliskieStarcie(const Card<T>& bliskie);
        BliskieStarcie& operator=(const BliskieStarcie<T>&) {return *this;};
        ~BliskieStarcie() { std::cout<<"Zniszczono karte"<<std::endl; };;
        void showInfo();
        std::vector<sf::Text> getValues();
};

template <class T>
class DalekiZasieg:public Card<T>{
    public:
        DalekiZasieg(std::string _name, std::string _details, T _points, std::string file_name);
        DalekiZasieg(const Card<T>& daleki);
        DalekiZasieg& operator=(const DalekiZasieg<T>&) {return *this;};
        ~DalekiZasieg() { std::cout<<"Zniszczono karte"<<std::endl; };;
        void showInfo();
        std::vector<sf::Text> getValues();
};

template <class T>
class JednostkaObl:public Card<T>{
    public:
        JednostkaObl(std::string _name, std::string _details, T _points, std::string file_name);
        JednostkaObl(const Card<T>& jednostka);
        JednostkaObl& operator=(const JednostkaObl<T>&) {return *this;};
        ~JednostkaObl() { std::cout<<"Zniszczono karte"<<std::endl; };;
        void showInfo();
        std::vector<sf::Text> getValues();
};


template <class T>
Card<T>* createObject(std::vector <std::string> array);


//IMPLEMENTACJA METOD I FUNKCJI


template <class T>
Card<T>::Card (std::string _name, std::string _type, std::string _details, T _points, std::string file_name): 
name{_name}, details{_details}, type{_type}, points{_points}
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

template <class T>
Card<T>::Card (const Card<T>& card):
name{card.getName()}, details{card.getDetails()}, type{card.getType()}, points{card.getPoints()},
sprite{card.getGraphics()} {}


template <class T>
Card<T>::~Card(){ std::cout<<"finito"; }

template <class T>
std::string Card<T>::getName() const {return name;}

template <class T>
std::string Card<T>::getType() const {return type;}

template <class T>
std::string Card<T>::getDetails() const { return details; }

template <class T>
T Card<T>::getPoints() const {return points;}

template <class T>
sf::Sprite Card<T>::getGraphics() const {return sprite;}

template <class T>
void Card<T>::setPoints(T value) { points = value;}


template <class T>
Przywodca<T>::Przywodca (std::string _name, std::string details, std::string file_name): 
Card<T>{_name, "Przywodca", details, 0, file_name} {}

template <class T>
Przywodca<T>:: Przywodca(const Card<T>& przywodca): Card<T>{przywodca} {}
template <class T>
void Przywodca<T>::showInfo(){
    std::cout<<this->getName()<<":"<<std::endl;
    std::cout<<"Typ karty: Przywodca"<<std::endl<<std::endl;
}


template <class T>
std::vector <sf::Text> Przywodca<T>::getValues(){
    std::vector <sf::Text> temp;
    std::stringstream ss, so;
    sf::Text name, points, details;

    ss << "Nazwa karty: " << this->getName();
    name.setString(ss.str());
    temp.push_back(name);

    points.setString("Przywodca nie posiada punktow");
    temp.push_back(points);

    so << "Opis przywódcy: " << this->getDetails();
    details.setString(so.str());
    temp.push_back(details);
    
    return temp;

}

template <class T>
BliskieStarcie<T>::BliskieStarcie(std::string _name, std::string _details, T _points, std::string file_name): 
Card<T>{_name, "Bliskie starcie", _details, _points, file_name} {}
template <class T>
BliskieStarcie<T>:: BliskieStarcie(const Card<T>& bliskie): Card<T>{bliskie} {}

//int BliskieStarcie::getPoints() const { return points; } 

template <class T>
void BliskieStarcie<T>::showInfo(){
    std::cout<<this->getName()<<":"<<std::endl;
    std::cout<<"Typ karty: Bliskie starcie"<<std::endl;
    std::cout<<"Liczba punktow: "<<this->getPoints()<<std::endl<<std::endl;
}

template <class T>
std::vector <sf::Text> BliskieStarcie<T>::getValues(){
    std::vector <sf::Text> temp;
    std::stringstream ss, so, sp;
    sf::Text name, details, points;

    ss << "Nazwa karty: " << this->getName();
    name.setString(ss.str());
    temp.push_back(name);

    sp << "Liczba punktow: " << std::to_string(this->getPoints());
    points.setString(sp.str());
    temp.push_back(points);

    so << "Opis postaci: " << this->getDetails();
    details.setString(so.str());
    temp.push_back(details);
    
    return temp;

}


template <class T>
DalekiZasieg<T>::DalekiZasieg(std::string _name, std::string _details, T _points, std::string file_name): 
Card<T>{_name, "Daleki zasieg", _details, _points, file_name} {}

template <class T>
DalekiZasieg<T>:: DalekiZasieg(const Card<T>& daleki): Card<T>(daleki){}

//int DalekiZasieg::getPoints() const { return points; } 

template <class T>
void DalekiZasieg<T>::showInfo(){
    std::cout<<this->getName()<<":"<<std::endl;
    std::cout<<"Typ karty: Daleki zasieg"<<std::endl;
    std::cout<<"Liczba punktow: "<<this->getPoints()<<std::endl<<std::endl;
}

template <class T>
std::vector <sf::Text> DalekiZasieg<T>::getValues(){
    std::vector <sf::Text> temp;
    std::stringstream ss, so, sp;
    sf::Text name, details, points;

    ss << "Nazwa karty: " << this->getName();
    name.setString(ss.str());
    temp.push_back(name);
    
    sp << "Liczba punktow: " << std::to_string(this->getPoints());
    points.setString(sp.str());
    temp.push_back(points);

    so << "Opis postaci: " << this->getDetails();
    details.setString(so.str());
    temp.push_back(details);
    
    return temp;

}

template <class T>
JednostkaObl<T>::JednostkaObl(std::string _name, std::string _details, T _points, std::string file_name): 
Card<T>{_name, "Jednostka obleznicza", _details, _points, file_name} {}

template <class T>
JednostkaObl<T>::JednostkaObl(const Card<T>& jednostka): Card<T>{jednostka} {}

//int JednostkaObl::getPoints() const { return points; } 

template <class T>
void JednostkaObl<T>::showInfo(){
    std::cout<<this->getName()<<":"<<std::endl;
    std::cout<<"Typ karty: Jednostka obleznicza"<<std::endl;
    std::cout<<"Liczba punktow: "<<this->getPoints()<<std::endl<<std::endl;
}

template <class T>
std::vector <sf::Text> JednostkaObl<T>::getValues(){
    std::vector <sf::Text> temp;
    std::stringstream ss, so, sp;
    sf::Text name, details, points;

    ss << "Nazwa karty: " << this->getName();
    name.setString(ss.str());
    temp.push_back(name);

    sp << "Liczba punktow: " << std::to_string(this->getPoints());
    points.setString(sp.str());
    temp.push_back(points);

    so << "Opis postaci: " << this->getDetails();
    details.setString(so.str());
    temp.push_back(details);
    
    return temp;

}

template <class T>
Card<T>* createObject(std::vector <std::string> array){
    std::string name = array.at(0);
    std::string type = array.at(1);
    std::string details = array.at(2);
    int points = std::stoi(array.at(3));
    std::string filename = array.at(4);
    Card<int> *temp;

    typedef std::vector<std:: string> StringContainer;
    typedef StringContainer::iterator StringIterator;
    std::vector <std::string> vec = {"Przywodca", "BliskieStarcie", 
                                    "DalekiZasieg", "JednostkaObl"};
    
    StringIterator position = std::find(vec.begin(), vec.end(), type);
    int index = std::distance(vec.begin(), position);
    
    try{
        if (!vec.at(index).compare("Przywodca")) temp = new Przywodca<int>(name, details, filename);
        else if (!vec.at(index).compare("BliskieStarcie")) temp = new BliskieStarcie<int>(name, details, points, filename);
        else if (!vec.at(index).compare("DalekiZasieg")) temp = new DalekiZasieg<int>(name, details, points, filename);
        else if (!vec.at(index).compare("JednostkaObl")) temp =  new JednostkaObl<int>(name, details, points, filename);
    }
    catch (std::out_of_range& e){ 
        throw std::out_of_range("Nie mozna odnalezc typu karty w wektorze typow!\n");
    }
    return temp;
}
