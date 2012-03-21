
#include "Imatge.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <cstdlib>
using namespace std;

Imatge::Imatge()
// s'ha cridat automàticament
// el constructor per defecte de _pixels
{
    _amplada = 0;
    _alsada = 0;
}

Imatge::Imatge(int amplada, int alsada)
: _pixels(amplada * alsada)
{
    _amplada = amplada;
    _alsada = alsada;
}

Imatge::Imatge(const Imatge& other)
: _pixels(other._pixels)
{
    _amplada = other._amplada;
    _alsada = other._alsada;
}

void Imatge::redimensiona(int amplada, int alsada) {
    vector<RGB> nouspixels(amplada * alsada);
    for (int i = 0; i < alsada; i++) {
        for (int j = 0; j < amplada; j++) {
            if (i < _alsada && j < _amplada) {
               nouspixels[i*amplada+j] = getpixel(i, j);
            }
        }
    }
    _pixels = nouspixels;
    _amplada = amplada;
    _alsada = alsada;
}

void Imatge::escriu(string nomfitxer) const {
    // http://en.wikipedia.org/wiki/Netpbm_format
    ofstream F(nomfitxer.c_str());
    F << "P3" << endl;
    F << _amplada << ' ' << _alsada << endl;
    F << 255 << endl;
    for (int i = 0; i < _pixels.size(); i++) {
       _pixels[i].escriu(F);
       F << endl;
    }
}

void Imatge::llegeix(string nomfitxer) {
    // http://en.wikipedia.org/wiki/Netpbm_format
    ifstream F(nomfitxer.c_str());
    if (!F.is_open()) {
        return;
    }
    string linia;
    getline(F, linia);
    if (linia != "P3") {
        return;
    }
    // Llegim comentaris
    getline(F, linia);
    while (linia[0] == '#') {
       getline(F, linia);
    }
    istringstream S(linia);
    S >> _amplada >> _alsada;

    _pixels.resize(_amplada * _alsada);
    int max;
    F >> max; // suposem que és 255
    int i = 0;
    for (i = 0; i < _pixels.size(); i++) {
       _pixels[i].llegeix(F);
    }
}



void RGB::escriu(ostream& o) const {
   o << r << ' ' << g << ' ' << b;
}

void RGB::llegeix(istream& i) {
   i >> r >> g >> b;
}

void Imatge::linia_v(int i, int j1, int j2, RGB valor) {
   if (j1 > j2) swap(j1, j2);
   for (int j = j1; j <= j2; j++) {
       setpixel(i, j, valor);
   }
}

void Imatge::linia_h(int j, int i1, int i2, RGB valor) {
   if (i1 > i2) swap(i1, i2);
   for (int i = i1; i <= i2; i++) {
       setpixel(i, j, valor);
   }
}
