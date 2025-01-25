#include <iostream>
#include <string>
#include <algorithm> // std::min()

class Chef {
protected:
    std::string chefName;

public:
    // Konstruktori
    Chef(const std::string& name) : chefName(name) {
        std::cout << "Chef Gordon konstruktor" << std::endl;
    }

    // Destruktori
    virtual ~Chef() {
        std::cout << "Chef Gordon destruktori" << std::endl;
    }

    std::string getName() const {
        return chefName;
    }

    int makeSalad(int ingredients) {
        int salads = ingredients / 5;
        std::cout << "Chef Gordon with " << ingredients
                  << " items can make salad " << salads << " portions" << std::endl;
        return salads;
    }

    int makeSoup(int ingredients) {
         int soups = ingredients / 3;
        std::cout << "Chef Gordon with " << ingredients
                  << " items can make soup " << soups << " portions" << std::endl;
        return soups;
    }
};

class ItalianChef : public Chef {
private:
    const std::string password = "pizza";
    int flour;
    int water;

    int makePizza(int flour, int water) {
        int pizzas = std::min(flour / 5, water / 5);
        std::cout << "ItalianChef Mario with " << flour
                  << " flour and " << water << " water can make " << pizzas
                  << " pizzas" << std::endl;
        return pizzas;
    }

public:
    // Konstruktori
    ItalianChef(const std::string& name, int initialFlour, int initialWater)
        : Chef(name), flour(initialFlour), water(initialWater) {
        std::cout << "Chef Mario konstruktor" << std::endl;
    }

    // Destruktori
    ~ItalianChef() {
        std::cout << "Italian Chef Mario destruktori" << std::endl;
    }

    bool askSecret(const std::string& inputPassword, int flourUsed, int waterUsed) {
        if (inputPassword.compare(password) == 0) {
            std::cout << "Password ok!" << std::endl;
            int pizzas = makePizza(flourUsed, waterUsed);
            return true;
        } else {
            std::cout << "Incorrect password!" << std::endl;
            return false;
        }
        if (flourUsed>flour || waterUsed>water){
            std::cout << "Not enough ingredients!" << std::ends;
            return false;
        }
    }

    void prepareSalad(int ingredients) {
        makeSalad(ingredients);
    }

    void prepareSoup(int ingredients) {
        makeSoup(ingredients);
    }
};

int main() {
    Chef chef("Chef Gordon");
    chef.makeSalad(11);
    chef.makeSoup(14);

    ItalianChef italianChef("Chef Mario", 50, 50);

    italianChef.prepareSalad(9);

    std::string passwordInput = "pizza";
    int flourInput = 12, waterInput = 12;

    if (italianChef.askSecret(passwordInput, flourInput, waterInput)) {
        std::cout << "Pizza preparation successful!" << std::endl;
    } else {
        std::cout << "Pizza preparation failed!" << std::endl;
    }
    return 0;
}









