
#include <iostream>
#include <fstream>
using namespace std;

int main() {
  string nom_fitxer;
  cout << "Nom de fitxer? ";
  cin >> nom_fitxer;
  ifstream F;
  F.open(nom_fitxer.c_str());
  while (!F.eof()) {
    string linia;
    getline(F, linia);
    cout << linia << endl;
  }
  F.close();
}
