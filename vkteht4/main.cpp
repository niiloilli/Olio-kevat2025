#include <iostream>
#include <string>

class Pankkitili {
protected:
    std::string omistaja;
    double saldo;

public:
    Pankkitili(const std::string& omistaja) : omistaja(omistaja), saldo(0) {
        std::cout << "Pankkitili luotu " << omistaja << ":lle\n";
    }

    virtual bool deposit(double amount) {
        if (amount <= 0) {
            return false;
        }
        saldo += amount;
        std::cout << "Bertta Pankkitili: talletus " << amount << " tehty\n";
        return true;
    }

    virtual bool withdraw(double amount) {
        if (amount <= 0 || amount > saldo) {
            return false;
        }
        saldo -= amount;
        std::cout << "Aapeli Pankkitili: nosto " << amount << " tehty\n";
        return true;
    }

    double getBalance() const {
        return saldo;
    }

    virtual ~Pankkitili() {}
};

class Luottotili : public Pankkitili {
private:
    double luottoRaja;

public:
    Luottotili(const std::string& omistaja, double luottoRaja)
        : Pankkitili(omistaja), luottoRaja(luottoRaja) {
        saldo = 0;
        std::cout << "Luottotili luotu " << omistaja << ":lle, luottoraja " << luottoRaja << "\n";
    }

    bool deposit(double amount) override {
        if (amount <= 0 || saldo + amount > 0) {
            return false;
        }
        saldo += amount;
        std::cout << "Luottotili: talletus " << amount << " tehty\n";
        return true;
    }

    bool withdraw(double amount) override {
        if (amount <= 0 || saldo - amount < -luottoRaja) {
            return false;
        }
        saldo -= amount;
        std::cout << "Luottotili: nosto " << amount << " tehty, luottoa jaljella " << luottoRaja + saldo << "\n";
        return true;
    }

    ~Luottotili() override {}
};

class Asiakas {
private:
    std::string nimi;
    Pankkitili kayttotili;
    Luottotili luottotili;

public:
    Asiakas(const std::string& nimi, double luottoRaja)
        : nimi(nimi), kayttotili(nimi), luottotili(nimi, luottoRaja) {
        std::cout << "Asiakkuus luotu " << nimi << "\n";
    }

    void showSaldo() const {
        std::cout << "Kayttotilin saldo: " << kayttotili.getBalance() << "\n";
        std::cout << "Luottotilin saldo: " << (luottotili.getBalance() == 0 ? 1000 : luottotili.getBalance() + 1000) << "\n";
    }

    bool talletus(double amount) {
        return kayttotili.deposit(amount);
    }

    bool nosto(double amount) {
        return kayttotili.withdraw(amount);
    }

    bool luotonMaksu(double amount) {
        return luottotili.deposit(amount);
    }

    bool luotonNosto(double amount) {
        return luottotili.withdraw(amount);
    }

    bool tiliSiirto(double amount, Asiakas& toinenAsiakas) {
        std::cout << "Pankkitili: " << nimi << " siirtaa " << amount << " " << toinenAsiakas.getNimi() << ":lle\n";
        if (amount <= 0 || !kayttotili.withdraw(amount)) {
            return false;
        }
        if (!toinenAsiakas.kayttotili.deposit(amount)) {
            kayttotili.deposit(amount);
            return false;
        }
        return true;
    }

    std::string getNimi() const {
        return nimi;
    }
};

int main() {
    Asiakas asiakas1("Aapeli", 1000);
    asiakas1.showSaldo();

    asiakas1.talletus(250);
    asiakas1.luotonNosto(150);
    asiakas1.showSaldo();

    Asiakas asiakas2("Bertta", 1000);
    asiakas2.showSaldo();

    std::cout << "Aapeli\n";
    asiakas1.showSaldo();

    asiakas1.tiliSiirto(50, asiakas2);

    std::cout << "Bertta\n";
    asiakas2.showSaldo();

    return 0;
}
