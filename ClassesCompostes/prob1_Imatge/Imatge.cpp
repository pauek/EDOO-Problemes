
#include "Imatge.h"
#include <fstream>
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
    vector<int> nouspixels(amplada * alsada);
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
    F << "P2" << endl;
    F << _amplada << ' ' << _alsada << endl;
    F << 255 << endl;
    cout << _pixels.size() << endl;
    for (int i = 0; i < _pixels.size(); i++) {
        F << _pixels[i] << endl;
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
    if (linia != "P2") {
        return;
    }
    // Suposem que hi ha una línia amb un comentari
    getline(F, linia); // llegim i ignorem el comentari
    F >> _amplada >> _alsada;
    cout << _amplada << ' ' << _alsada << endl;
    _pixels.resize(_amplada * _alsada);
    int max;
    F >> max; // suposem que és 255
    int i = 0;
    for (i = 0; i < _pixels.size(); i++) {
        F >> _pixels[i];
    }
    cout << i << endl;
}















































