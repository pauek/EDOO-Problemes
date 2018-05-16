// Twitter

#include <iostream>
#include <fstream>
#include <unordered_map>
#include <unordered_set>
using namespace std;

unordered_set<string> interseccio(const unordered_set<string>& A, 
                                  const unordered_set<string>& B) 
{
   unordered_set<string> res;
   for (auto it = A.begin(); it != A.end(); it++) {
      if (B.find(*it) != B.end()) {
         res.insert(*it);
      }
   }
   return res;
}

int main() {
   unordered_map<string, unordered_set<string>> followers;
   ifstream T("twitter.txt");
   string user1, user2;
   while (T >> user1 >> user2) {
      followers[user2].insert(user1);
   }

   cout << "Entra dos usuarios: ";
   while (cin >> user1 >> user2) {
      auto comunes = interseccio(followers[user1], followers[user2]);
      cout << "Seguidores comunes de '" << user1 << "' y '" << user2 << "'" << endl;
      cout << "{ ";
      for (auto it = comunes.begin(); it != comunes.end(); it++) {
         if (it != comunes.begin()) {
            cout << ", ";
         }
         cout << *it;
      }
      cout << " }" << endl;
      cout << "Entra dos usuarios: ";
   }
}