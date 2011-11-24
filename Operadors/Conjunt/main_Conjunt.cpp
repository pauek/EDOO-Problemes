
#include "Conjunt.h"
#include <iostream>
using namespace std;

int main() {
   Conjunt A, B, C;
   cout << "Conjunt A? ";
   cin >> A;
   cout << "Conjunt B? ";
   cin >> B;
   cout << endl;
   cout << "A + B:     " << A + B << endl;
   cout << "A - B:     " << A - B << endl;
   cout << "B - A:     " << B - A << endl;
   cout << "A && B:    " << (A && B) << endl;
   cout << "A > B:     " << (A > B) << endl;
   cout << "A >= B:    " << (A >= B) << endl;
   cout << "A < B:     " << (A < B) << endl;
   cout << "A <= B:    " << (A <= B) << endl;
   cout << "A == B:    " << (A == B) << endl;
   cout << "A != B:    " << (A != B) << endl;
}
