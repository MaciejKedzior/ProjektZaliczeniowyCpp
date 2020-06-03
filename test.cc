#include <iostream>
#include <string>
#include "window.hpp"


int main(){
    Card *geralt = new BliskieStarcie("Geralt z Rivii", "Wiedzmin i gbur", 15, "Karty/geralt.jpg");
    geralt->showInfo();
    Window menu("Font/arial.ttf", geralt);
    menu.run(geralt);

    return 0;
}