#include "window.h"

void setSprite(Window *win, Card *card){
    win->sprite = card->getGraphics();
}

Window::Window(const std::string& _font, Card *card):
font (loadFont(_font)),
tr_back (createShape(50.f, 3, sf::Vector2f(600.f, 500.f), 270.f)),
tr_forward (createShape(50.f, 3, sf::Vector2f(850.f, 400.f), 90.f)),
window(sf::VideoMode(666, 500), "Gwint"){
    setSprite(this, card);
    //initialize();
}

//void Window::initialize(){
//
//}

void Window::run(Card *card){
    sf::Event event;
    while(window.isOpen()){
        while(window.pollEvent(event)){
            if(sf::Event::Closed){
                delete card;
                window.close();
            }    
        }
        window.clear();
        window.draw(tr_forward);
        window.draw(tr_back);
    }
}