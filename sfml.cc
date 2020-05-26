#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <vector>
#include <iterator>
#include "functions.h"
#include "game.h"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <sstream>


int main(void){
    std::vector <sf::Text> values;
    std::vector <Card*> cards;
    sf::Font font;
    sf::Text nazwa, punkty, opis;
    int index = 0;

    
    cards.emplace_back(new BliskieStarcie("Geralt z Rivii", "Wiedzmin i gbur", 15, "geralt.jpg"));
    cards.emplace_back(new DalekiZasieg("Keira Metz", "Czarodziejka z Temerii", 5, "keiraok.jpg"));
    cards.emplace_back(new JednostkaObl("Katapulta", "Oh jak ogromna!", 8, "katapulta.jpg"));
    cards.emplace_back(new BliskieStarcie("Komandos Niebieskich Pasow", "Chlop na schwal", 3, "komandos.jpg"));

    
    values = cards.at(index)->getValues();
    sf::Sprite sprite = cards.at(index)->getGraphics();

    font = loadFont("arial.ttf");

    nazwa = createTextBox(values.at(0), 25, &font, sf::Vector2f(500.f, 150.f));
    punkty = createTextBox(values.at(1), 25, &font, sf::Vector2f(500.f, 190.f));
    opis = createTextBox (values.at(2), 15, &font, sf::Vector2f(530.f, 270.f));
    

    sf::RenderWindow window(sf::VideoMode(1024.f, 656.f), "Gwint - talia");
    window.setFramerateLimit(60);
    
    sf::CircleShape triangle_back = createShape(50.f, 3, sf::Vector2f(600.f, 500.f), 270.f);
    sf::CircleShape triangle_fwd = createShape(50.f, 3, sf::Vector2f(850.f, 400.f), 90.f);



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
                                sprite = cards.at(--index)->getGraphics();
                                values = cards.at(index)->getValues();

                                cards.at(index)->showInfo();

                                nazwa = createTextBox(values.at(0), 25, &font, sf::Vector2f(500.f, 150.f));
                                punkty = createTextBox(values.at(1), 25, &font, sf::Vector2f(500.f, 190.f));
                                opis = createTextBox(values.at(2), 15, &font, sf::Vector2f(530.f, 270.f));
                            }
                        }
                        if(forward.contains(position)){
                            if (index == 3) continue;
                            else {
                                sprite = cards.at(++index)->getGraphics();
                                values = cards.at(index)->getValues();
                                cards.at(index)->showInfo();
                                
                                nazwa = createTextBox(values.at(0), 25, &font, sf::Vector2f(500.f, 150.f));
                                punkty = createTextBox(values.at(1), 25, &font, sf::Vector2f(500.f, 190.f));
                                opis = createTextBox(values.at(2), 15, &font, sf::Vector2f(530.f, 270.f));
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
