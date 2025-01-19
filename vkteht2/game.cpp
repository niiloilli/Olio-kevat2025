#include "game.h"
#include "Game.h"
#include <iostream>
#include <cstdlib> // std::rand, std::srand
#include <ctime>   // std::time
#include <limits>

Game::Game(int maxNum) : maxNumber(maxNum), playerGuess(0), numOfGuesses(0) {
    std::cout << "GAME CONSTRUCTOR: Objekti alustettu. Suurin luku " << maxNumber << "." << std::endl;

    std::srand(std::time(0));
    randomNumber = std::rand() % maxNumber + 1;
}

Game::~Game() {
}

void Game::printGameResult() {
    std::cout << "Tulostetaan pelin tulos" << std::endl;
    std::cout << "Oikea vastaus oli: " << randomNumber << std::endl;
    std::cout << "Arvasit oikein " << numOfGuesses << " arvauksella!" << std::endl;
}

void Game::play() {
    std::cout << "Peli aloitettu" << std::endl;
    std::cout << "Arvaa tietokoneen arpoma luku valilta 1-" << maxNumber << "." << std::endl;

    while (true) {
        std::cout << "Anna arvauksesi: ";
        std::cin >> playerGuess;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Anna kelvollinen kokonaisluku!" << std::endl;
            continue;
        }

        numOfGuesses++;
        std::cout << playerGuess << std::endl;

        if (playerGuess < randomNumber) {
            std::cout << "Luku on suurempi." << std::endl;
        } else if (playerGuess > randomNumber) {
            std::cout << "Luku on pienempi." << std::endl;
        } else {
            std::cout << "Oikein!" << std::endl;
            break;
        }
    }

    printGameResult();
}
