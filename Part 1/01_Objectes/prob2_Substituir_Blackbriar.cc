
#include <iostream>
using namespace std;

int main() {
  string frase;
  getline(cin, frase);
  int pos = frase.find("Blackbriar");
  if (pos != -1) {
    frase.replace(pos, 10, "<piip>");
  }  
  cout << frase << endl;
}
