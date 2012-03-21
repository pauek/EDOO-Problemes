
#ifndef DIASETMANA_H
#define DIASETMANA_H

class DiaSetmana {
   int _n; // 0 = dilluns, 1 = dimarts, ..., 6 = diumenge
public:
   DiaSetmana() { _n = 0; }
   DiaSetmana(string dia);

   bool igual(const DiaSetmana& altre) const { 
      return _n == altre._n; 
   }

   void avansa(int dies) {
      _n = (_n + dies) % 7;
   }

   void mostra(ostream& o) const;
};

#endif
