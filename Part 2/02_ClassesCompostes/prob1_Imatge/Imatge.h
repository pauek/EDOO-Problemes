#ifndef IMATGE_H
#define IMATGE_H

#include <vector>
#include <string>
using namespace std;

class Imatge {
    vector<int> _pixels;
    int _amplada, _alsada;
public:
    Imatge();
    Imatge(const Imatge& other);
    Imatge(int amplada, int alsada);

    int amplada() const { return _amplada; }
    int alsada()  const { return _alsada; }

    int getpixel(int i, int j) const {
        return _pixels[i*_amplada + j];
    }

    void setpixel(int i, int j, int valor) {
        _pixels[i*_amplada + j] = valor;
    }

    void redimensiona(int amplada, int alsada);

    void escriu(string nomfitxer) const;
    void llegeix(string nomfitxer);
};

#endif // IMATGE_H
