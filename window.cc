#include "window.hpp"

void setSprite(Window *win, Card <int>*card){
    win->sprite = card->getGraphics();
}

Window::Window(const std::string& _font, std::vector<Card <int>*> cards):
    font (loadFont(_font)),
    tr_back (createShape(50.f, 3, sf::Vector2f(600.f, 500.f), 270.f)),
    tr_forward (createShape(50.f, 3, sf::Vector2f(850.f, 400.f), 90.f)),
    window(sf::VideoMode(1024, 656), "Gwint"){
        setSprite(this, cards.at(0));

    }


Window::~Window(){std::cout<<"koniec okna\n"; };


void Window::run(std::vector <Card <int>*> cards){
    sf::Event event;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed){
                for (auto& i: cards) delete i;
                window.close();
            }
        }

        window.clear();
        window.draw(tr_forward);
        window.draw(tr_back);
        window.draw(sprite);
        window.display();
    }
}
