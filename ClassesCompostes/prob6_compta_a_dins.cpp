
int compta_a_dins(const vector<DataHora>& v, 
                  const DataHora& inici, const DataHora& final) {
   vector<DataHora>::const_iterator it = v.begin();
   int cont = 0;
   for (; it != v.end(); it++) {
      if ((*it).posterior(inici) && (*it).anterior(final)) {
         cont++;
      }
   }
   return cont;
}
