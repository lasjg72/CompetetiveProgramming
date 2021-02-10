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
   int n, k;
   cin >> n >> k;
   map<int, ll> a;
   for(int i = 0; i < n; i++){
       int num;
       cin >> num;
       a[num]++;
   }
   ll ans = 0;
   for(int i = 0; i < n; i++){
       if(a[i] < k){
           ans += i*(k-a[i]);
           k = a[i];
           if(k == 0){
               break;
           }
       }
       if(i == n-1){
           ans += (i+1) * k;
       }
   }
   cout << ans << endl;
   return 0;
}