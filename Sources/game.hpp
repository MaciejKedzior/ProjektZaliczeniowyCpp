#ifndef GAME_h
#define GAME_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>


/**Funkcja naprawiająca znak \n na znak \n rozumiany jako znak nowej linii*/
std::string& fix_newlines(std::string& s);

/**Funkcja załadowująca plik czcionki celem stworzenia obiektu sf::Font*/
sf::Font loadFont(const std::string& font);

/**Funkcja tworząca obiekt sf::CircleShape o podanych jako argumenty własnościach*/
sf::CircleShape createShape(float radius, std::size_t pointCount, sf::Vector2f position, float rotation);

/**Funkcja tworząca obiekt sf::Text o podanych jako argumenty własnościach, przeładowana*/
sf::Text createTextBox(sf::Text text, int size, sf::Font *font, sf::Vector2f position);
sf::Text createTextBox(std::string text, int size, sf::Font *font, sf::Vector2f position);

/**Funkcja rozdzielająca std::string na słowa na podstawie delimiter, 
 * zwraca std::vector z rozdzielonymi fragmentami*/
std::vector<std::string> splitString(std::string s, std::string delimiter);

#endif
