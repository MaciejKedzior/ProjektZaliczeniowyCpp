# ProjektZaliczeniowyCpp  
Projekt zaliczeniowy z przedmiotu C++ UJ WFAIS Maciej Kędzior, Kraków 2020  
  
Tytuł projektu: Gwint - przeglądarka kart gry karciana z uniwersum Wiedźmina  
  
Opis: Program służy jako przeglądarka kart Gwinta, wyświetla obrazek, dane dot. karty oraz opis postaci/obiektu 
  
Zawartość: <stan na 05.06.2020> podstawowe działanie klas kart, dziedziczących klas, obsługa pliku z danymi do stworzenia talii kart, w pełni działający program okienkowy napisany przy pomocy bibliteki SFML wyświetlający obrazek i dane postaci, guziki do nawigacji (karta wstecz, karta naprzód, wyjście z programu)  
  
Sposób uruchomienia: 1) git clone link_do_repo  2) wejść do podfolderu Sources 3) użyć komendy make 4) uruchomić program gwint.x 
    
UWAGA: Aby program zadziałał poprawnie konieczne jest zainstalowanie na komputerze biblioteki SFML dla C++ oraz wszelkich zależności przez niej przewidywanych:  
    pthread  
    opengl  
    xlib  
    xrandr  
    udev  
    freetype  
    openal  
    flac  
    vorbis  
    
 Zagadnienia wraz z miejscem w kodzie:    
1. Projekt obiektowy:  
- klasy - card.hpp, window.hpp  
- konstruktory, destruktory - card.hpp (linijki 12 i 23)    
- konstruktor kopiujący  - card.hpp (linijka 13)  
- deklaracja przyjaciela - window.hpp (linijka 20)  
- dziedziczenie - card.hpp (klasa Przywodca, linijka 33)  
- polimorfizm - card.hpp (klasa Card linijka 15, klasa Przywodca linijka 40)  
- klasa abstrakcyjna - card.hpp (klasa Card)  
- czysto wirtualne metody - card.hpp (klasa Card, linijki 15 i 16)     
  
2. STL  
- szablony -  
- iteratory - card.cc (linijka 189)  
- algorytmy - card.cc (linika 190)  
  
3. C++  
- zakresowa pętla for - window.cc (linijka 129)  
- własny szablon klasy (lub funkcji)  
- przeciążanie operatorów - card.hpp (linijka 14)  
- wyjątki - card.cc (linijka 192)  
- plik .h z deklaracja i .cpp z definicją metod - jest  
- linker - jest
