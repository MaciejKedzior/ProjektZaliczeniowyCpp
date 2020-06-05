#include "window.hpp"


void Window::swapCards(std::vector <Card *> cards, const std::string& opcode){
    if (!opcode.compare("backwards"))   --index;
    else if (!opcode.compare("forward")) ++index;

    sprite = cards.at(index)->getGraphics();
    text_areas = cards.at(index)->getValues();
    cards.at(index)->showInfo();                           
    to_be_printed[0] = createTextBox(text_areas.at(0), 25, &font, sf::Vector2f(530.f, 170.f));
    to_be_printed[1] = createTextBox(text_areas.at(1), 25, &font, sf::Vector2f(530.f, 210.f));
    to_be_printed[2] = createTextBox(text_areas.at(2), 20, &font, sf::Vector2f(530.f, 270.f));
}


Window::Window(const std::string& _font, std::vector<Card *> cards):
    index (0),
    number_of_cards (cards.size()-1),
    font (loadFont(_font)),
    legend (createTextBox("Strzalka w lewo/Left-wstecz, strzalka w prawo/Right-przod,\nprostokat/ESC-wyjdz z programu", 
    15, &font, sf::Vector2f(530.f, 600.f))),
    tr_back (createShape(50.f, 3, sf::Vector2f(600.f, 500.f), 270.f)),
    tr_forward (createShape(50.f, 3, sf::Vector2f(850.f, 400.f), 90.f)),
    exit_button (sf::Vector2f(250.f, 50.f)),
    window(sf::VideoMode(1024, 656), "Gwint"){
            if(!logo_texture.loadFromFile("../Graphics/gwent.png")){
            std::cout<<"Error loading file\n";
            exit(EXIT_FAILURE);
        }
        logo_texture.setSmooth(true);
        logo_texture.setRepeated(true);

        logo.setTexture(logo_texture);
        logo.setPosition(620.f, 35.f);

        exit_button.setFillColor(sf::Color::Cyan);
        exit_button.setPosition(600.f, 520.f);

        setSprite(this, cards.at(0));
        text_areas = cards.at(0)->getValues();
        to_be_printed[0] = createTextBox(text_areas.at(0), 25, &font, sf::Vector2f(530.f, 170.f));
        to_be_printed[1] = createTextBox(text_areas.at(1), 25, &font, sf::Vector2f(530.f, 210.f));
        to_be_printed[2] = createTextBox(text_areas.at(2), 20, &font, sf::Vector2f(530.f, 270.f));
    }


Window::~Window(){std::cout<<"koniec okna\n"; };


void Window::handleEvents(std::vector<Card *> cards){
    sf::Event event;
    while(window.pollEvent(event)){
        switch(event.type){
            case sf::Event::Closed:
                std::cout<<"Exit button pressed\n";
                closeWindow(cards);
            case sf::Event::KeyPressed:
                if (event.key.code == sf::Keyboard::Escape){
                    std::cout<<"Escape pressed\n";
                    closeWindow(cards);
                }

                if (event.key.code == sf::Keyboard::Left){
                    if (index == 0) continue;
                    else swapCards(cards, "backwards");
                }

                if (event.key.code == sf::Keyboard::Right){
                    if (index == number_of_cards) continue;
                    else swapCards(cards, "forward");
                }
            case sf::Event::MouseButtonPressed:
                if (event.mouseButton.button == sf::Mouse::Left){
                    sf::Vector2f position = sf::Vector2f(sf::Mouse::getPosition(window));
                    std::map<std::string, sf::Rect<float>> buttons;
                    buttons["backwards"] = tr_back.getGlobalBounds();
                    buttons["forward"] = tr_forward.getGlobalBounds();
                    buttons["exit_button"] = exit_button.getGlobalBounds();

                    if(buttons["backwards"].contains(position)){
                        if (index == 0) continue;
                        else swapCards(cards, "backwards");
                    }
                    if(buttons["forward"].contains(position)){
                        if (index == number_of_cards) continue;
                        else swapCards(cards, "forward");
                    }
                    if(buttons["exit_button"].contains(position)){
                        std::cout<<"Rectangle pressed\n";
                        closeWindow(cards);
                    }
                }
                break;
            default:
                break;
            }
        }

}

void setSprite(Window *win, Card *card){
    win->sprite = card->getGraphics();
}

void Window::drawStuff(){
        window.clear();
        window.draw(logo);
        window.draw(tr_forward);
        window.draw(tr_back);
        window.draw(sprite);
        window.draw(to_be_printed[0]); window.draw(to_be_printed[1]); window.draw(to_be_printed[2]);
        window.draw(exit_button);
        window.draw(legend);
        window.display();
}


void Window::run(std::vector <Card *> cards){
    while (window.isOpen()){
        handleEvents(cards);
        drawStuff();
    }
}


void Window::closeWindow(std::vector<Card *> cards){
    window.clear();
    for (auto& i: cards) delete i;  //uwolnienie pamięci
    window.close();
    exit(EXIT_SUCCESS);
}