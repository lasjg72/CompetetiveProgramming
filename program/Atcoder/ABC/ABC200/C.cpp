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
using P = pair<int, int>;

int main()
{
   int n;
   cin >> n;
   vector<int> a(n);
   map<int, ll> mp;
   for(int i = 0; i < n; i++){
       cin >> a[i];
       a[i] %= 200;
       mp[a[i]]++;
   }
   ll ans = 0;
   for(int i = 0; i < 200; i++){
           ll now = mp[i];
           //cout << now << endl;
           ans += now*(now-1)/2;
   }
   cout << ans << endl;
   return 0;
}