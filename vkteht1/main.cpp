#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>

int game(int maxnum);

int main() {
    int maxLuku;
    std::cout << "Anna korkein etsittava luku: ";
    std::cin>>maxLuku;

    int arvaustenMaara=game(maxLuku);

    std::cout<<"Arvasit oikein " << arvaustenMaara << " arvauksella. \n";

    return 0;
}

int game(int maxnum){
    std::srand(std::time(0));
    int arvottuLuku = std::rand() % maxnum + 1;

    int arvaus;
    int arvaustenMaara=0;

    std::cout << "Arvaa tietokoneen arpoma luku valilta 1- " <<maxnum<< ". \n" << std::ends;

    while (true){
        std::cout << "Arvauksesi: ";
        std::cin >> arvaus;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Anna kelvollinen kokonaisluku!" << std::endl;
            continue;
        }

        arvaustenMaara++;

        if (arvaus < arvottuLuku) {
            std::cout << "Luku on suurempi." << std::endl;
        } else if (arvaus > arvottuLuku) {
            std::cout << "Luku on pienempi." << std::endl;
        } else {
            std::cout << "Oikein! Arvottu luku oli: " << arvottuLuku << std::endl;
            break;
        }
    }

    return arvaustenMaara;
}
