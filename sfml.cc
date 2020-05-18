#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <vector>
#include <iterator>
#include "functions.h"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <sstream>


int main(void){
    std::vector <sf::Text> values;
    std::vector <Card*> cards;
/*
    Card* geralt = new BliskieStarcie("Geralt z Rivii", "Wiedzmin i gbur", 15, "geralt.jpg");
    Card* keira = new DalekiZasieg("Keira Metz", "Czarodziejka z Temerii", 5, "keiraok.jpg");
    cards.emplace_back(new BliskieStarcie(*geralt));
    cards.emplace_back(new DalekiZasieg(*keira));
*/
    cards.emplace_back(new BliskieStarcie("Geralt z Rivii", "Wiedzmin i gbur", 15, "geralt.jpg"));
    cards.emplace_back(new DalekiZasieg("Keira Metz", "Czarodziejka z Temerii", 5, "keiraok.jpg"));
    cards.emplace_back(new JednostkaObl("Katapulta", "Oh jak ogromna!", 8, "katapulta.jpg"));
    cards.emplace_back(new BliskieStarcie("Komandos Niebieskich Pasow", "Chlop na schwal", 3, "komandos.jpg"));
    for (auto& i: cards) i->showInfo();


    int index = 1;

    cards.at(index)->showInfo();
    values = cards.at(index)->getValues();
    sf::Sprite sprite = cards.at(index)->getGraphics();

    sf::Font font;
    if(!font.loadFromFile("arial.ttf")){
        std::cout<<"Error while loading font!";
        exit(EXIT_FAILURE);
    }
    
    sf::Text nazwa, punkty, opis;
    nazwa = values.at(0);
    punkty = values.at(1);
    opis = values.at(2);

    nazwa.setFont(font);
    nazwa.setCharacterSize(30);
    nazwa.setPosition(600.f, 150.f);

    punkty.setFont(font);
    punkty.setCharacterSize(30);
    punkty.setPosition(600.f, 190.f);

    opis.setFont(font);
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
                    for (auto& i: cards) delete i;
                    window.close();
                    break;
                case sf::Event::KeyPressed:
                    if (event.key.code == sf::Keyboard::Escape){
                        window.clear();
                        for (auto& i: cards) delete i;
                        window.close();
                        std::cout<<"Escape pressed\n";
                        exit(EXIT_SUCCESS);
                    }
                case sf::Event::MouseButtonPressed:
                    if (event.mouseButton.button == sf::Mouse::Left){
                        sf::Vector2f position = sf::Vector2f(sf::Mouse::getPosition(window));
                        sf::Rect<float> backwards = triangle_back.getGlobalBounds();
                        sf::Rect<float> forward = triangle_fwd.getGlobalBounds();
                        sf::Rect<float> menu = main_menu.getGlobalBounds();
                        if(backwards.contains(position)){
                            if (index == 0) continue;
                            else {
                                window.clear();
                                sprite = cards.at(--index)->getGraphics();
                                values = cards.at(index)->getValues();

                                cards.at(index)->showInfo();
                                window.clear();
                                nazwa = values.at(0);   nazwa.setPosition(600.f, 150.f);
                                punkty = values.at(1);  punkty.setPosition(600.f, 190.f);
                                opis = values.at(2);    opis.setPosition(530.f, 270.f);
                                window.draw(nazwa);
                                window.draw(punkty);
                                window.draw(opis);
                            }
                        }
                        if(forward.contains(position)){
                            if (index == 3) continue;
                            else {
                                sprite = cards.at(++index)->getGraphics();
                                values = cards.at(index)->getValues();
                                cards.at(index)->showInfo();
                                window.clear();
                                nazwa = values.at(0);   nazwa.setPosition(600.f, 150.f);
                                punkty = values.at(1);  punkty.setPosition(600.f, 190.f);
                                opis = values.at(2);    opis.setPosition(530.f, 270.f);
                                window.draw(nazwa);
                                window.draw(punkty);
                                window.draw(opis);
                            }
                        }
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