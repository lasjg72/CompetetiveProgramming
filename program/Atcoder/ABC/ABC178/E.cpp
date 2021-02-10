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
    ll n;
    cin >> n;
    vector<ll> f1(n), f2(n);
    for(ll i = 0; i < n; i++){
        ll x, y;
        cin >> x >> y;
        f1[i] = (x - y);
        f2[i] = (x + y);
    }
    // cout << abs(f1mx-f1mi) << endl;
    // cout << abs(f2mx-f2mi) << endl;
    sort(f1.begin(), f1.end());
    sort(f2.begin(), f2.end());
    ll ans = max(abs(f1[0]-f1[n-1]), abs(f2[0]-f2[n-1]));
    cout << ans << endl;
    return 0;
}