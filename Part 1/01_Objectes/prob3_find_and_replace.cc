
#include <iostream>
using namespace std;

void find_and_replace(string& frase, string p, string q) {
  int pos = frase.find(p);
  while (pos != -1) {
    frase.replace(pos, p.size(), q);
    pos = frase.find(p, pos + q.size());
  }
}

int main() {
  string frase;
  getline(cin, frase);
  find_and_replace(frase, "Blackbriar", "<piip>");
  cout << frase << endl;
}
