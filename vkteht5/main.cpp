#include <iostream>
#include <string>

class Seuraaja {
private:
    std::string nimi;
    Seuraaja* next;

public:
    Seuraaja(std::string nimi) : nimi(nimi), next(nullptr) {}

    void setNext(Seuraaja* seuraava) {
        next = seuraava;
    }

    Seuraaja* getNext() const {
        return next;
    }

    std::string getNimi() const {
        return nimi;
    }

    void paivitys(const std::string& viesti) {
        std::cout << nimi << " sai viestin " << viesti << std::endl;
    }
};

class Notifikaattori {
private:
    Seuraaja* seuraajat;

public:
    Notifikaattori() : seuraajat(nullptr) {}

    void lisaa(Seuraaja* uusiSeuraaja) {
        uusiSeuraaja->setNext(seuraajat);
        seuraajat = uusiSeuraaja;
        std::cout << "Notifikaattori lisaa seuraajan " << uusiSeuraaja->getNimi() << std::endl;
    }

    void poista(Seuraaja* poistettava) {
        Seuraaja* nykyinen = seuraajat;
        Seuraaja* edellinen = nullptr;

        while (nykyinen != nullptr) {
            if (nykyinen == poistettava) {
                if (edellinen == nullptr) {
                    // Poistettava on ensimmainen alkio
                    seuraajat = nykyinen->getNext();
                } else {
                    // Ohitetaan poistettava alkio
                    edellinen->setNext(nykyinen->getNext());
                }
                std::cout << "Notifikaattori poistaa seuraajan " << poistettava->getNimi() << std::endl;
                return;
            }
            edellinen = nykyinen;
            nykyinen = nykyinen->getNext();
        }
    }

    void tulosta() const {
        std::cout << "Notifikaattorin seuraajat:" << std::endl;
        Seuraaja* nykyinen = seuraajat;
        while (nykyinen != nullptr) {
            std::cout << nykyinen->getNimi() << std::endl;
            nykyinen = nykyinen->getNext();
        }
    }

    void postita(const std::string& viesti) const {
        std::cout << "Notifikaattori postaa viestin " << viesti << std::endl;
        Seuraaja* nykyinen = seuraajat;
        while (nykyinen != nullptr) {
            nykyinen->paivitys(viesti);
            nykyinen = nykyinen->getNext();
        }
    }
};

int main() {
    std::cout << "Luodaan notifikaattori" << std::endl;
    Notifikaattori n;

    std::cout << "Luodaan seuraaja A" << std::endl;
    Seuraaja a("A");

    std::cout << "Luodaan seuraaja B" << std::endl;
    Seuraaja b("B");

    std::cout << "Luodaan seuraaja C" << std::endl;
    Seuraaja c("C");

    n.lisaa(&a);
    n.lisaa(&b);
    n.lisaa(&c);
    n.tulosta();

    n.postita("Tama on viesti 1");
    n.poista(&b);
    n.postita("Tama on viesti 2");

    return 0;
}



