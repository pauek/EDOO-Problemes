
#include "miniwin.h"
using namespace miniwin;

#include "Rectangle.h"

void anima(Rectangle& R, float dx, float dy) {
   for (int i = 0; i < 460; i++) {
      borra();
      R.pinta();
      refresca();
      R.mou(dx, dy);
      espera(2);
   }
}

int main() {
   vredimensiona(500, 500);
   Rectangle R(0, 0, 40, 40, ROJO);
   anima(R, 1, 0);
   anima(R, 0, 1);
   anima(R, -1, 0);
   anima(R, 0, -1);
   vcierra();
}
