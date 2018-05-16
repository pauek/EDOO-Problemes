
#include <iostream>
#include <map>
#include <fstream>
using namespace std;

map<string, char> llegeix_taula(string fitxer) {
   ifstream F(fitxer);
   string linia;
   map<string, char> taula;
   while (getline(F, linia)) {
      char lletra = linia[0];
      string morse = linia.substr(2);
      taula[morse] = lletra;
   }
   return taula;
}

int main() {
   map<string, char> morse = llegeix_taula("morse.csv");

   ifstream F("morse.txt");
   string lletra;
   while (F >> lletra) {
      cout << morse[lletra];
   }
}
