//#include <iostream>
//#include <SFML/System.hpp>
//#include <SFML/Window.hpp>
//#include <SFML/Graphics.hpp>
#include "game.h"


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