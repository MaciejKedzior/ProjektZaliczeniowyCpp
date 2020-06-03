#ifndef WINDOW_h
#define WINDOW_H

#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include "game.hpp"
#include "card.hpp"


class Window{
    public:
        Window(const std::string& _font, Card *card);
        ~Window();
        friend void setSprite(Window *win, Card *card);
        void run(Card *card);
    private:
        void initialize();
        sf::Font            font;
        sf::Sprite          sprite;
        sf::RenderWindow    window;
        sf::CircleShape     tr_back, tr_forward;
        sf::RectangleShape  main_menu;
};

#endif