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

using namespace std;
using ll = long long;

int main()
{
   double t;
   int n;
   cin >> t >> n;
   auto calc = [&](double p, double x){
       return (100+p)*x/100;
   };
   ll l = 0, r = 1001001001001001001;
   while(r-l>1){
       ll mid = (l+r)/2;
       //cout << "r: " << r << " l: " << l << endl;
       double now = calc(t, (double)mid);
       if((ll)(now-mid) < n){
           l = mid;
       }else{
           r = mid;
       }
   }
   cout << (ll)calc(t, l)+1 << endl;
   return 0;
}