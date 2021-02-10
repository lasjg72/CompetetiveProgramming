#include <iostream>
#include <algorithm>
#include <tuple>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include <set>
#include <map>

using namespace std;
using ll = long long;
const int mod = 1e9+7;

int main()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    for(int i = 0; i< n ;i++){
        cin >> a[i];
    }
    ll ans = 0;
    for(int i = 0; i< 60; i++){
        ll x = 0, y = 0;
        for(int j = 0; j< n; j++){
            if(a[j]>>i&1) x++;
            else y++;
        }
        ll total = 0;
        total = (x * y) % mod;
        for(int j = 0; j< i; j++){
            total = total * 2 % mod;
        }
        ans += total;
        ans %= mod;
    }
    cout << ans << endl;
    return 0;
}