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
    if(n == 0) return 1;
    else if(n%2) return modpow(x, n-1)*x%mod;
    else return modpow(x, n/2)*modpow(x, n/2)%mod;
}

int main()
{
    int n;
    cin >> n;
    if(n == 1) cout << 0 << endl;
    else cout << ((modpow(10, n)-((modpow(9, n)+modpow(9, n))%mod-modpow(8, n)+mod)%mod)+mod)%mod << endl;
    return 0;
}