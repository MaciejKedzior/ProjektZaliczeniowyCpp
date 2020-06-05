#ifndef WINDOW_h
#define WINDOW_H

#include <vector>
#include <array>
#include <map>
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

#include "game.hpp"
#include "card.hpp"


class Window{
    public:
        Window(const std::string& _font, std::vector <Card *> cards);
        ~Window();
        friend void setSprite(Window *win, Card *card);
        void run(std::vector <Card *> cards);
        void drawStuff();
        void closeWindow(std::vector<Card *> cards);
        void handleEvents(std::vector<Card *> cards);
    private:
        int                     index;
        int                     number_of_cards;
        void                    initialize();
        sf::Font                font;
        sf::Text                legend;
        sf::Sprite              sprite, logo;
        sf::Texture             logo_texture;
        sf::CircleShape         tr_back, tr_forward;
        sf::RenderWindow        window;
        sf::RectangleShape      exit_button;
        std::vector<sf::Text>   text_areas;
        std::array<sf::Text, 3> to_be_printed;
};

#endif
