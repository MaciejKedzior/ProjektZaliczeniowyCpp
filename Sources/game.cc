#include "card.hpp"
#include <fstream>


std::string& fix_newlines(std::string& s){
    size_t start_pos = 0;
    while((start_pos = s.find("\\n", start_pos)) != std::string::npos) {
         s.replace(start_pos, 2, "\n");
         start_pos += 1;
    }
    return s;
}

sf::Font loadFont(const std::string& font){
    sf::Font temp;
    if(!temp.loadFromFile(font)){
        std::cout<<"Error while loading font from file\n";
        exit(EXIT_FAILURE);
    }
    return temp;
}

sf::CircleShape createShape(float radius, std::size_t pointCount, sf::Vector2f position, float rotation){
    sf::CircleShape temp(radius, pointCount);
    temp.setFillColor(sf::Color::Cyan); 
    temp.setPosition(position);
    temp.setRotation(rotation);
    return temp;
}

sf::Text createTextBox(std::string text, int size, sf::Font *font, sf::Vector2f position){
    sf::Text textbox;
    textbox.setString(text);
    textbox.setFont(*font);
    textbox.setCharacterSize(size);
    textbox.setPosition(position);
    return textbox;
}


sf::Text createTextBox(sf::Text text, int size, sf::Font *font, sf::Vector2f position){
    sf::Text textbox = text;
    textbox.setFont(*font);
    textbox.setCharacterSize(size);
    textbox.setPosition(position);
    return textbox;
}


std::vector<std::string> splitString(std::string s, std::string delimiter){
    std::vector <std::string> temp;
    size_t position=0;
    std::string token;

    while( (position = s.find(delimiter)) != std::string::npos){
        token = s.substr(0, position);
        temp.push_back(token);
        s.erase(0, position + delimiter.length());
    }
    temp.push_back(s);

    return temp;
}


std::vector <Card *> loadObjects(const std::string& file_name){
    std::string wiersz;
    std::vector <std::vector <std::string>> testy;
    std::vector <Card *> obiekty;
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
        obiekty.emplace_back(createObject(i));
    
    return obiekty;
}
