#include <iostream>
#include <algorithm>
#include <tuple>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include <set>
#include <map>
#include <cassert>
#include <iomanip>

using namespace std;
using ll = long long;

int main()
{
   int n;
   cin >> n;
   vector<double> x(n);
   double man = 0, yu = 0, bi = 0;
   for(int i = 0; i < n; i++){
       cin >> x[i];
       man += abs(x[i]);
       bi = max(bi, abs(x[i]));
   }
   double tmp = 0;
   for(int i = 0; i < n; i++){
       tmp += pow(abs(x[i]), 2);
   }
   yu = sqrt(tmp);
   cout << fixed << setprecision(15) << man << endl;
   cout << fixed << setprecision(15) << yu << endl;
   cout << fixed << setprecision(15) << bi << endl;
   return 0;
}