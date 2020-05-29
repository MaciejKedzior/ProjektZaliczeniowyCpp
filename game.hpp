#ifndef GAME_h
#define GAME_H

#include <iostream>
#include <vector>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

sf::Font loadFont(const std::string& font);

sf::CircleShape createShape(float radius, std::size_t pointCount, sf::Vector2f position, float rotation);

sf::Text createTextBox(sf::Text text, int size, sf::Font *font, sf::Vector2f position);
sf::Text createTextBox(std::string text, int size, sf::Font *font, sf::Vector2f position);


std::vector<std::string> splitString(std::string s, std::string delimiter);

#endif
