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
using P = pair<ll, ll>;

ll modpow(ll n, ll x){
    if(x == 0) return 1;
    else if(x%2 == 0) return modpow(n, x/2)*modpow(n, x/2);
    else return modpow(n, x-1)*n;
}

int main()
{
    ll n, p;
    cin >> n >> p;
    ll ans = 1;
    vector<P> d;
    for(ll i = 2; i*i <= p; i++){
        ll num = 0;
        while(p%i == 0){
            p /= i;
            num++;
        }
        d.push_back({i, num});
    }
    if(p != 1) d.push_back({p, 1});
    for(P now : d){
        // cout << now.first << " " << now.second/n << endl;
        // cout << modpow(now.first, now.second/n) << endl;
        ans *= modpow(now.first, now.second/n);
    }
    cout << ans << endl;
    return 0;
}