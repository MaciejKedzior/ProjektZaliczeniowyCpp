#ifndef FUNCTIONS_h
#define FUNCTIONS_H
#include <vector>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>


class Card{     
    public:
        Card (std::string _name, std::string _type, std::string _details, int _points, std::string file_name);
        Card (const Card &card);
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
        Przywodca (const Card& przywodca);
        ~Przywodca () { std::cout<<"Zniszczono karte"<<std::endl; };
        void showInfo(); 
        std::vector<sf::Text> getValues();
};

class BliskieStarcie:public Card{
    public:
        BliskieStarcie(std::string _name, std::string _details, int _points, std::string file_name);
        BliskieStarcie(const Card& bliskie);
        ~BliskieStarcie() { std::cout<<"Zniszczono karte"<<std::endl; };;
        void showInfo();
        std::vector<sf::Text> getValues();
        //int getPoints() const;
    //private:
        //int points;
};

class DalekiZasieg:public Card{
    public:
        DalekiZasieg(std::string _name, std::string _details, int _points, std::string file_name);
        DalekiZasieg(const Card& daleki);
        ~DalekiZasieg() { std::cout<<"Zniszczono karte"<<std::endl; };;
        void showInfo();
        std::vector<sf::Text> getValues();
        //int getPoints() const;
    //private:
        //int points;
};

class JednostkaObl:public Card{
    public:
        JednostkaObl(std::string _name, std::string _details, int _points, std::string file_name);
        JednostkaObl(const Card& jednostka);
        ~JednostkaObl() { std::cout<<"Zniszczono karte"<<std::endl; };;
        void showInfo();
        std::vector<sf::Text> getValues();
        //int getPoints() const; 
    //private:
        //int points;
};


std::vector<std::string> splitString(std::string s, std::string delimiter);
Card* createObject(std::vector <std::string> array);

#endif