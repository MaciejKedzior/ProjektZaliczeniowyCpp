#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include "functions.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <sstream>

int main(void){    
    Card* geralt = new DalekiZasieg("Geralt z Rivii", 15, "geralt.jpg");
    sf::Sprite sprite = geralt->getGraphics();
    std::string nazwa_str;
    std::string punkty_str;
    std::stringstream ss, sp;

    ss << "Nazwa karty: " << geralt->getName();
    nazwa_str = ss.str();
    
    sp << "Liczba punktow: " << std::to_string(geralt->getPoints());
    punkty_str = sp.str();

    sf::Font font;
    if(!font.loadFromFile("arial.ttf")){
        std::cout<<"font dupa";
        exit(EXIT_FAILURE);
    }

    sf::Text nazwa, punkty, opis;
    nazwa.setFont(font);
    nazwa.setString(nazwa_str);
    nazwa.setCharacterSize(30);
    nazwa.setPosition(600.f, 150.f);

    punkty.setFont(font);
    punkty.setString(punkty_str);
    punkty.setCharacterSize(30);
    punkty.setPosition(600.f, 190.f);

    opis.setFont(font);
    opis.setString(L"geralt gołodupiec - wiedźmin i pijak xD");
    opis.setCharacterSize(15);
    opis.setPosition(530.f, 270.f);


    sf::RenderWindow window(sf::VideoMode(1024.f, 656.f), "Gwint - talia");
    window.setFramerateLimit(60);
    
    sf::CircleShape triangle_back(50.f, 3), triangle_fwd(50.f, 3);
    triangle_back.setFillColor(sf::Color::Cyan); triangle_fwd.setFillColor(sf::Color::Cyan);
    triangle_back.setPosition(600.f, 500.f); triangle_fwd.setPosition(850.f, 400.f);
    triangle_back.setRotation(270.f); triangle_fwd.setRotation(90.f);

    sf::RectangleShape main_menu(sf::Vector2f(250.f, 50.f));
    main_menu.setFillColor(sf::Color::Cyan);
    main_menu.setPosition(600.f, 520.f);


    while(window.isOpen()){
        sf::Event event;
        while(window.pollEvent(event)){
            switch(event.type){
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::KeyPressed:
                    if (event.key.code == sf::Keyboard::Escape){
                        window.clear();
                        std::cout<<"Escape pressed\n";
                        exit(EXIT_SUCCESS);
                    }
                case sf::Event::MouseButtonPressed:
                    if (event.mouseButton.button == sf::Mouse::Left){
                        sf::Vector2f position = sf::Vector2f(sf::Mouse::getPosition(window));
                        sf::Rect<float> backwards = triangle_back.getGlobalBounds();
                        sf::Rect<float> forward = triangle_fwd.getGlobalBounds();
                        sf::Rect<float> menu = main_menu.getGlobalBounds();
                        if(backwards.contains(position)) std::cout<<"Do tyłu!\n";
                        if(forward.contains(position)) std::cout<<"Do przodu!\n";
                        if(menu.contains(position)) std::cout<<"Powrót do menu głównego!\n";
                    }
                    else if (event.mouseButton.button == sf::Mouse::Right) std::cout<<"Right clicked\n";
                    break;
                default:
                    break;
            }
        }
        window.clear();
        window.draw(triangle_back); window.draw(triangle_fwd);
        window.draw(main_menu);
        window.draw(sprite);
        window.draw(nazwa);
        window.draw(punkty);
        window.draw(opis);
        
        window.display();
    }
    
    return 0;
}