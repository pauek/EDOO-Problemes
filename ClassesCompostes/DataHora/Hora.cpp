
#include <iostream>
#include <sstream>
#include <ctime>
#include <cassert>
using namespace std;

#include "Hora.h"

Hora::Hora() {
   time_t raw;
   time(&raw);
   struct tm *info;
   info = localtime(&raw);
   _hor = info->tm_hour;
   _min = info->tm_min;
   _seg = info->tm_sec;
}

Hora::Hora(const Hora& other) {
   _hor = other._hor;
   _min = other._min;
   _seg = other._seg;
}

Hora::Hora(int h, int m, int s) {
   _hor = h;
   _min = m;
   _seg = s;
}

void Hora::desde_segons(int segons) {
   assert(segons >= 0); // Requisit: segons no pot ser negatiu
   _hor = (segons / 3600) % 24;
   segons %= 3600;
   _min = (segons / 60);
   segons %= 60;
   _seg = segons;
}

const int SEGONS_PER_DIA = 24 * 60 * 60;

int Hora::incrementa(int segons) {
   assert(segons >= 0); // Requisit: segons no pot ser negatiu
   // Hem de mirar si al sumar segons passem al dia seguent...
   int total = a_segons() + segons;
   int dies = total / SEGONS_PER_DIA;
   desde_segons(total % SEGONS_PER_DIA);
   return dies;
}

bool Hora::anterior(const Hora& altra) const {
   return a_segons() < altra.a_segons();
}

bool Hora::igual(const Hora& altra) const {
   return a_segons() == altra.a_segons();
}

bool Hora::posterior(const Hora& altra) const {
   return a_segons() > altra.a_segons();
}

// Retorna la "distància" (positiva) entre les dues
Hora Hora::diferencia(const Hora& altra) const {
    Hora resultat;
    if (posterior(altra)) {
       resultat.desde_segons(a_segons() - altra.a_segons());
    } else {
       resultat.desde_segons(altra.a_segons() - a_segons());
    }
    return resultat;
}

string en2(int n) {
   ostringstream S;
   if (n < 10) S << '0';
   S << n;
   return S.str();
}

void Hora::escriu(ostream& o) const {
   o << en2(_hor) << ':' << en2(_min) << ':' << en2(_seg);
}

void Hora::llegeix(istream& i) {
   char p; // per llegir els ':' que ignorarem
   i >> _hor >> p >> _min >> p >> _seg;
}

