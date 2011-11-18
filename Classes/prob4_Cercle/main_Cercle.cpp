
#include "miniwin.h"
using namespace miniwin;

#include "Cercle.h"

void fila(Cercle& C) {
   C.pinta(); C.mou(50, 0);
   C.pinta(); C.mou(50, 0);
   C.pinta(); C.mou(-100, 50);
}

void upc(Cercle& C) {
   fila(C); fila(C); fila(C);
}

int main() {
   vredimensiona(400, 400);
   Cercle C(200, 200, 19, BLANCO);
   C.mou(-50, -50);
   upc(C);
}
