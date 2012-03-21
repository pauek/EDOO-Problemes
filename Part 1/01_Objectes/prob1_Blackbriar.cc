
#include <iostream>
using namespace std;

int main() {
  string frase;
  getline(cin, frase);
  if (frase.find("Blackbriar") != -1) {
    cout << "ALERTA!" << endl;
  }  
}
