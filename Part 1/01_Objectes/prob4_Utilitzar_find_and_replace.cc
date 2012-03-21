
#include <iostream>
#include <fstream>
using namespace std;

void find_and_replace(string& frase, string p, string q) {
  int pos = frase.find(p);
  while (pos != -1) {
    frase.replace(pos, p.size(), q);
    pos = frase.find(p, pos + q.size());
  }
}

int main() {
  ifstream fin;
  ofstream fout;
  
  fin.open("escrit.txt");
  fout.open("escrit_corregit.txt");
  while (!fin.eof()) {
    string linia;
    getline(fin, linia);
    find_and_replace(linia, " q ", " que ");
    fout << linia << endl;
  }
  fin.close();
  fout.close();
}
