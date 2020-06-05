#include "window.hpp"

int main(){
    std::vector <Card*> objects = loadObjects("../Data/dane_wejsciowe");
    Window menu("../Data/arial.ttf", objects);
    menu.run(objects);
    return 0;
}
