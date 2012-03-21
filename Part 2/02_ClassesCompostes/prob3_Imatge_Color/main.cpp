#include <iostream>
using namespace std;

#include "Imatge.h"

int main() {
    Imatge I;
    I.llegeix("jobs.pnm");
    cout << I.amplada() << ' ' << I.alsada() << endl;
    I.afegir_soroll(100);
    I.binaritza();
    I.escriu("sortida.pnm");
}
