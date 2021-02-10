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

// ll modPow(long long a, long long n, long long p) {
//   if (n == 0) return 1; // 0乗にも対応する場合
//   if (n == 1) return a % p;
//   if (n % 2 == 1) return (a * modPow(a, n - 1, p)) % p;
//   long long t = modPow(a, n / 2, p);
//   return (t * t) % p;
// }

int main()
{
    ll n, x, m;
    cin >> n >> x >> m;
    // ll b = modPow(x, 2*n, m);
    // ll ans = (x-b)/(1-x*x);
    vector<ll> a, num(m+10, -1);
    ll len = 0;
    ll tot = 0;
    a.push_back(x);
    while(num[x] == -1){
      num[x] = len;
      tot += x;
      x = (x*x)%m;
      len++;
      a.push_back(x);
    }
    ll cyc = len - num[x]; //1周分の長さ
    ll ans = 0, s = 0; //サイクル1周分のxの総和
    for(ll i = num[x]; i < len; i++){
      s += a[i];
    }
    if(n <= len){
      for(ll i = 0; i < n; i++){
        ans += a[i];
      }
    }else{
      ans += tot;
      n -= len;
      ll tmp = n/cyc; //何周するか
      ans += tmp * s;
      for(ll i = 0; i < n % cyc; i++){
        ans += a[i+num[x]];
      }
    }
    cout << ans << endl;
    return 0;
}