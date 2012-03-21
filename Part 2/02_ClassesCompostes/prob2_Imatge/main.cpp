#include <iostream>
using namespace std;

#include "Imatge.h"

int main() {
    Imatge I;
    I.llegeix("groucho.pgm");
    I.afegir_soroll(100);
    I.escriu("sortida.pnm");
}
