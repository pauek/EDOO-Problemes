
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

string prefix(string nom_fitxer) {
  int pos = nom_fitxer.find('.');
  if (pos == -1) pos = nom_fitxer.size();
  return nom_fitxer.substr(0, pos);
}

string genera_nom(string prefix, int n) {
  stringstream S;
  S << prefix << n << ".txt"; // suposem extensió .txt
  return S.str();
}

int main() {
  string nom_fitxer;
  cout << "Nom fitxer? ";
  cin >> nom_fitxer;
  int N;
  cout << "Número de línies? ";
  cin >> N;
  
  string pre = prefix(nom_fitxer);
  int num = 1; // fitxers que portem
  int lin = 0; // línies que portem
  ifstream fin;
  ofstream fout;
  string linia;

  fin.open(nom_fitxer.c_str());
  string nom = genera_nom(pre, num);
  fout.open(nom.c_str());
  getline(fin, linia);
  while (!fin.eof()) {
    lin++;
    if (lin > N) {
      fout.close();
      num++;
      nom = genera_nom(pre, num);
      fout.open(nom.c_str());
    }
    fout << linia << endl;
    getline(fin, linia);
  }
  fin.close();
  fout.close();
}
