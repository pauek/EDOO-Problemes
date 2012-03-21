
#include <iostream>
using namespace std;

#include "Imatge.h"
#include "Pinzell.h"

int main() {
   RGB col;
   int x, y, n;
   char c;

   cin >> x >> y;

   Imatge I(x, y);
   Pinzell P(I);

   cin >> c;
   while (c != '.') {
      if (c == 'H') {
         cin >> n;
         P.horiz(n);
      } else if (c == 'V') {
         cin >> n;
         P.vert(n);
      } else if (c == 'C') {
         cin >> col.r >> col.g >> col.b;
         P.color(col);
      } else if (c == '+' || c == '-') {
         P.pinta(c == '+');
      }
      cin >> c;
   }

   I.escriu("img.pnm");
}
