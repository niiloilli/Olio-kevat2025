#include <iostream>
#include "Game.h"

int main() {
    std::cout << "Ohjelma aloitettu" << std::endl;

    int maxLuku;
    std::cout << "Anna korkein etsittava luku: ";
    std::cin >> maxLuku;

    Game peli(maxLuku);

    peli.play();

    std::cout << "Ohjelma paattyy" << std::endl;
    return 0;
}
