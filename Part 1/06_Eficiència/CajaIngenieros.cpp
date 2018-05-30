/*

Caja Ingenieros
---------------

La Caja de Ingenieros hace un sorteo para premiar el uso de sus tarjetas de
crédito durante el 2013. Se dispone de un fichero compras2013.txt con las
compras hechas por cada tarjeta con el formato siguiente

   20130102 4444-4444-4444-4444  20.99
   20130102 1111-1111-1111-1111 127.39
   20130203 9999-9999-9999-9999  73.29
   20130213 1111-1111-1111-1111  52.40
   20130217 4444-4444-4444-4444  12.62
   20130302 4444-4444-4444-4444  18.61
   20130315 1111-1111-1111-1111  35.75
   20130322 1111-1111-1111-1111  22.80
   20130403 9999-9999-9999-9999  44.70
   20130613 9999-9999-9999-9999  89.52
   20130817 4444-4444-4444-4444   5.99
   20131017 4444-4444-4444-4444  12.64
   20131017 4444-4444-4444-4444  13.62
   20131105 9999-9999-9999-9999  61.11
   20131220 9999-9999-9999-9999 151.81
   20131224 9999-9999-9999-9999  44.69

Primero hay la fecha en formato AAAAMMDD, luego el número de tarjeta de
crédito, y finalmente el importe. El orden del fichero es cronológico. El
sorteo se hace entre aquellos clientes que cumplan los siguientes requisitos:

   1) Haber hecho almenos 6 compras.
   2) Que el total de compras ascienda a 200€ o más.
   3) Que el periodo de tiempo entre la primera y la última compra es de almenos 
      180 días (unos 6 meses).

El programa debe leer los datos del fichero compras2013.txt y producir un
fichero candidatos.txt con los códigos de las tarjetas, una por línea, de los
clientes candidatos al premio.

Con los datos anteriores, el fichero candidatos.txt será

   9999-9999-9999-9999

Para averiguar la diferencia de días entre dos fechas, puedes suponer que
existe ya la función 

   int dif_fechas(int f1, int f2) 

que devuelve el número de días que separan dos fechas.

*/

#include <iostream>
#include <fstream>
#include <map>
using namespace std;

int dif_fechas(int a, int b);

class Compres {
   float _import;
   int _num_compres, _datamin, _datamax;
public:
   Compres(); // constructor per defecte
   void afegeix(int data, float import);
   bool candidat() const;
};

int main() {
   map<string, Compres> compres;

   string tarjeta;
   int data;
   float import;

   ifstream F("compras2013.txt");
   while (F >> data >> tarjeta >> import) {
      // Quan es crea la parella de string i compra, 
      // per a la compra s'utilitza el constructor per defecte
      compres[tarjeta].afegeix(data, import);
   }

   ofstream C("candidatos.txt");
   for (auto it = compres.begin(); it != compres.end(); it++) {
      if (it->second.candidat()) {
         C << it->first << endl;
      }
   }
}

Compres::Compres() {
   _num_compres = 0;
   _import = 0.0;
   cout << "compres" << endl;
}

void Compres::afegeix(int data, float import) {
   if (_num_compres == 0) {
      _datamin = data;
      _datamax = data;
   }
   _num_compres++;
   _import += import;
   if (dif_fechas(data, _datamin) > 0) {
      _datamin = data;
      cout << this << " datamin " << data << endl;
   }
   if (dif_fechas(_datamax, data) > 0) {
      _datamax = data;
      cout << this << " datamax " << data << endl;
   }
}

bool Compres::candidat() const {
   return (_num_compres >= 6 && 
           _import > 200.0 && 
           dif_fechas(_datamin, _datamax) > 6*30);
}

/** Aquesta part es dona per feta en el problema **/

struct Data { int dia, mes, any; };

Data descomposa(int aaaammdd) {
   return { aaaammdd % 100, aaaammdd / 100 % 100, aaaammdd / 10000 };
}

// Aquesta funció passa una data al número de dies que han passat desde 0001-01-01
// https://en.wikipedia.org/wiki/Rata_Die
int rdn(Data d) {
    if (d.mes < 3) {
        d.any--;
        d.mes += 12;
    }
    return 365*d.any + d.any/4 - d.any/100 + d.any/400 + (153*d.mes - 457)/5 + d.dia - 306;
}

int dif_fechas(int aaaammdd1, int aaaammdd2) {
   return rdn(descomposa(aaaammdd2)) - rdn(descomposa(aaaammdd1));
}
