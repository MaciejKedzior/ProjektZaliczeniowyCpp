#include "

template <typename T>
sf::Text createTextBox(T text, int size, sf::Font font, sf::Vector2f position){
    sf::Text textbox;
    textbox.setString(text);
    textbox.setFont(font);
    textbox.setCharacterSize(size);
    textbox.setPosition(position);
    return textbox;
}