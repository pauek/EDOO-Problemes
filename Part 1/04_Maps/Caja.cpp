// Caja

#include <iostream>
#include <fstream>
#include <map>
using namespace std;

int main() {
   // Fase 1: Carregar la llista de preus
   ifstream P("precios.txt");
   map<int, float> precios;
   int codigo, unidades;
   float precio;
   while (cin >> codigo >> precio) {
      precios[codigo] = precio;
   }

   // Fase 2: Calcular el valor de les ventes
   float total = 0.0;
   ifstream V("ventas.txt");
   while (V >> codigo >> unidades) {
      // suposem que els codis sempre estaran al catàleg.
      total += unidades * precios[codigo];
   }
   cout << "Total = " << total << endl;
}