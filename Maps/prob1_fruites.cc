
#include <map>
#include <iostream>
#include <fstream>
using namespace std;

int main() {
   ifstream F;
   map<string, int> Fruites;
   F.open("fruites.txt");
   string fruita;
   int quant;
   F >> fruita >> quant;
   while (!F.eof()) {
      map<string, int>::iterator it = Fruites.find(fruita);
      if (it != Fruites.end()) {
         (*it).second += quant;
      } else {
         Fruites[fruita] = quant;
      }
      F >> fruita >> quant;
   }
   
   int total = 0;
   map<string, int>::iterator it = Fruites.begin();
   for (; it != Fruites.end(); it++) {
      cout << (*it).first << ' ' << (*it).second << endl;
      total += (*it).second;
   }
   cout << endl << "Total: " << total << endl;
}
