#include <iostream>
#include <string>
#include "window.h"
#include "functions.h"
#include "game.h"


int main(){
    Card *geralt = new BliskieStarcie("Geralt z Rivii", "Wiedzmin i gbur", 15, "Karty/geralt.jpg");
    Window menu("Font/arial.tff", geralt);
    menu.run(geralt);

    return 0;
}