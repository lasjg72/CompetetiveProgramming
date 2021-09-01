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
const int mod = 1e9+7;

ll modpow(ll x, ll n){
    if(x < 0) return 0;
    if(n == 0) return 1;
    else if(n%2 == 0) return (modpow(x, n/2)*modpow(x, n/2))%mod;
    else return (modpow(x, n-1)*x)%mod;
}

int main()
{
    ll n;
    ll k;
    cin >> n >> k;
    ll ans = 0;
    if(n >= 2){
        ll tmp = k*(k-1)%mod;
        ans = tmp*modpow(k-2, n-2);
        ans %= mod;
    }else{
        ans = k;
    }
    cout << ans << endl;
    return 0;
}