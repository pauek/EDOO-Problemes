#include <iostream>
using namespace std;

#include "Imatge.h"

int main() {
    Imatge I;
    I.llegeix("H:\\groucho.pgm");
    I.escriu("C:\\sortida.pnm");
}
