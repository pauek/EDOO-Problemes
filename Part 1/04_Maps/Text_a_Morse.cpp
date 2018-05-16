
#include <iostream>
#include <map>
#include <fstream>
using namespace std;

map<char, string> llegeix_taula(string fitxer) {
   ifstream F(fitxer);
   string linia;
   map<char, string> morse;
   while (getline(F, linia)) {
      char lletra = linia[0];
      string codi = linia.substr(2);
      morse[tolower(lletra)] = codi;
   }
   return morse;
}

int main() {
   map<char, string> morse = llegeix_taula("morse.csv");
  
   ifstream F("missatge.txt");
   string linia;
   while (getline(F, linia)) {
      for (int i = 0; i < linia.size(); i++) {
         auto it = morse.find(linia[i]);
         if (it != morse.end()) {
            cout << it->second << ' ';
         }
      }
   }
}
