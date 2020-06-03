#include "window.hpp"

void setSprite(Window *win, Card *card){
    win->sprite = card->getGraphics();
}

Window::Window(const std::string& _font, Card *card):
    font (loadFont(_font)),
    tr_back (createShape(50.f, 3, sf::Vector2f(600.f, 500.f), 270.f)),
    tr_forward (createShape(50.f, 3, sf::Vector2f(850.f, 400.f), 90.f)),
    window(sf::VideoMode(1024, 656), "Gwint"){
        setSprite(this, card);
        //initialize();
    }


Window::~Window(){std::cout<<"koniec okna\n"; };


void Window::run(Card *card){
    sf::Event event;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed){
                delete card;
                window.close();
            }
        }

        window.clear();
        window.draw(tr_forward);
        window.draw(tr_back);
        window.display();
    }
}