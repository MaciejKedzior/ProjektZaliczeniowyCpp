#ifndef GAME_h
#define GAME_H

#include <iostream>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

sf::Font loadFont(const std::string& font);

sf::CircleShape createShape(float radius, std::size_t pointCount, sf::Vector2f position, float rotation);

sf::Text createTextBox(sf::Text text, int size, sf::Font *font, sf::Vector2f position);
sf::Text createTextBox(std::string text, int size, sf::Font *font, sf::Vector2f position);
/*template <typename T>
sf::Text createTextBox(T text, int size, sf::Font font, sf::Vector2f position){
    sf::Text textbox;
    textbox.setFont(font);
    textbox.setCharacterSize(size);
    textbox.setPosition(position);
    return textbox;
}
template <>
sf::Text createTextBox<std::string>{
    sf::Text textbox;
    textbox.setFont(font);
    textbox.setCharacterSize(size);
    textbox.setPosition(position);
    return textbox;
}

template <>
sf::Text createTextBox<sf::Text>{
    sf::Text textbox = text;
    textbox.setCharacterSize(size);
    textbox.setPosition(position);
    return textbox;
}*/
#endif