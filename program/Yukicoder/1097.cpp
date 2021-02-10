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
    vector<ll> a(n);
    vector<ll> ans(n);
    for(ll i = 0; i< n ;i++){
        cin >> a[i];
    }
    ll x = 0, r;
    auto ope = [&](ll &x){
        r = x % n;
        x += a[r];
    };
    ll q;
    cin >> q;
    vector<ll> k(q);
    ll mk = 0;
    for(ll i = 0; i < q; i++){
        cin >> k[i];
        mk = max(k[i], mk);
    }
    cout << "mk: " << mk << endl;

    for(ll i = 0; i < mk; i++){
        ope(x);
        cout << "x: " << x << endl;
        cout << i << endl;
        ans[i] = x;
    }
    for(ll i = 0; i< q; i++){
        cout << ans[k[i]-1] << endl;
    }

    return 0;
}