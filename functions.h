#ifndef FUNCTIONS_h
#define FUNCTIONS_H
#include <vector>
#include <iostream>


class Card{     
    public:
        Card (std::string _name, std::string _type);
        virtual void showInfo()=0;
        std::string getName() const;
        std::string getType() const;
        virtual ~Card()=0;
    private:
        std::string name;
        std::string type;
};

class Przywodca:public Card{
    public:
        Przywodca (std::string _name);
        ~Przywodca ();
        void showInfo(); 
};

class BliskieStarcie:public Card{
    public:
        BliskieStarcie(std::string _name, int _points);
        ~BliskieStarcie();
        void showInfo();
        int getPoints() const;
    private:
        int points;
};

class DalekiZasieg:public Card{
    public:
        DalekiZasieg(std::string _name, int _points);
        ~DalekiZasieg();
        void showInfo();
        int getPoints() const;
    private:
        int points;
};

class JednostkaObl:public Card{
    public:
        JednostkaObl(std::string _name, int _points);
        ~JednostkaObl();
        void showInfo();
        int getPoints() const; 
    private:
        int points;
};


std::vector<std::string> splitString(std::string s, std::string delimiter);
Card* createObject(std::vector <std::string> array);


#endif