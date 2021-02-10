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
   ll n;
   cin >> n;
   ll ans = 0;
   for(ll i = 1; i*i <= 2*n; i++){
       if(2*n % i == 0){
           ll now = 2*n/i;
           //if(now < i) break;
           //cout << "now: " << now << "i: " << i << endl;
           if(!(now%2 == 0 && i%2 == 0)) {
               ans+=2;
               if(now == i) ans--;
           }
       }
   }
   cout << ans << endl;
   return 0;
}