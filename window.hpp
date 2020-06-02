#ifndef WINDOW_h
#define WINDOW_H

#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include "game.hpp"
#include "card.hpp"


class Window{
    public:
        Window(const std::string& _font, std::vector <Card <int>*> cards);
        ~Window();
        friend void setSprite(Window *win, Card <int>*card);
        void run(std::vector <Card <int>*> cards);
    private:
        void initialize();
        sf::Font            font;
        sf::Sprite          sprite;
        sf::RenderWindow    window;
        sf::CircleShape     tr_back, tr_forward;
        sf::RectangleShape  main_menu;
};

#endif
