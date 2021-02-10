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

int main()
{
    ll n;
    cin >> n;
    map<ll, ll> a;
    ll mx = 0;
    auto bunkai = [&](ll x){
        ll tmp = x;
        for(ll i = 2; i*i <= tmp; i++){
            if(x % i == 0){
                mx = max(i, mx);
            }
        }
        if(mx == 0) mx = max(x, mx);
        return mx;
    };
    ll yaku = bunkai(n);
    ll ans = (yaku-1) + (n/yaku -1);
    cout << ans << endl;
    return 0;
}