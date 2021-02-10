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
    ll n, k;
    cin >> n >> k;
    ll min=0, max=0;
    auto minx = [&](ll x){
        min = x * (x-1) / 2;
    };
    auto maxx = [&](ll x){
        max = (2*n-x+1) * x / 2;
    };
    ll ans = 0;
    for(ll i = k; i <= n+1; i++){
        minx(i);
        maxx(i);
        ll add = max - min + 1;
        ans = (ans + add)%mod;
    } 
    cout << ans << endl;
    return 0;
}