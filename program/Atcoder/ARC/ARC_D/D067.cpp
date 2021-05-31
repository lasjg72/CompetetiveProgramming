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
    ll n, a, b;
    cin >> n >> a >> b;
    vector<ll> x(n);
    for(int i = 0; i < n; i++){
        cin >> x[i];
    }
    ll ans = 0;
    for(int i = 1; i < n; i++){
        ll cost = (x[i]-x[i-1])*a;
        if(cost > b) ans += b;
        else ans += cost;
    }
    cout << ans << endl;
    return 0;
}