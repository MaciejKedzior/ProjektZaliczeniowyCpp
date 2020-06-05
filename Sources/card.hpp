#ifndef CARD_h
#define CARD_H
#include <vector>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
//#include "game.hpp"

class Card{     
    public:
        Card (std::string _name, std::string _type, std::string _details, int _points, std::string file_name);
        Card (const Card &card);
        Card& operator=(const Card&) {return *this;};
        virtual void showInfo()=0;
        virtual std::vector<sf::Text> getValues()=0;
        std::string getName() const;
        std::string getType() const;
        std::string getDetails() const;
        int getPoints() const;
        sf::Sprite getGraphics() const;
        void setPoints(int value);
        virtual ~Card()=0;
    private:
        std::string details;
        sf::Texture texture;
        std::string name;
        std::string type;
        int points;
        sf::Sprite sprite;
};

class Przywodca:public Card{
    public:
        Przywodca (std::string _name, std::string _details, std::string file_name);
        Przywodca* clone();
        Przywodca& operator=(const Przywodca&) {return *this;};
        Przywodca (const Card& przywodca);
        ~Przywodca () { std::cout<<"Zniszczono karte"<<std::endl; };
        void showInfo(); 
        std::vector<sf::Text> getValues();
};

class BliskieStarcie:public Card{
    public:
        BliskieStarcie(std::string _name, std::string _details, int _points, std::string file_name);
        BliskieStarcie(const Card& bliskie);
        BliskieStarcie& operator=(const BliskieStarcie&) {return *this;};
        ~BliskieStarcie() { std::cout<<"Zniszczono karte"<<std::endl; };;
        void showInfo();
        std::vector<sf::Text> getValues();
};

class DalekiZasieg:public Card{
    public:
        DalekiZasieg(std::string _name, std::string _details, int _points, std::string file_name);
        DalekiZasieg(const Card& daleki);
        DalekiZasieg& operator=(const DalekiZasieg&) {return *this;};
        ~DalekiZasieg() { std::cout<<"Zniszczono karte"<<std::endl; };;
        void showInfo();
        std::vector<sf::Text> getValues();
};

class JednostkaObl:public Card{
    public:
        JednostkaObl(std::string _name, std::string _details, int _points, std::string file_name);
        JednostkaObl(const Card& jednostka);
        JednostkaObl& operator=(const JednostkaObl&) {return *this;};
        ~JednostkaObl() { std::cout<<"Zniszczono karte"<<std::endl; };;
        void showInfo();
        std::vector<sf::Text> getValues();
};



Card* createObject(std::vector <std::string> array);

std::vector <Card *> loadObjects(const std::string& file_name);
#endif
