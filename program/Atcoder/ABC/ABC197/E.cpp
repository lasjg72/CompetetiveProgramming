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
const int INF = 1001001001;
ll dp[100005][2];

int main()
{
    ll n;
    cin >> n;
    vector<ll> x(n), c(n);
    ll ans = 0;
    vector<ll> l(n, INF), r(n, -INF);
    for(int i = 0; i < n; i++){
        cin >> x[i] >> c[i];
        c[i]--;
        l[c[i]] = min(l[c[i]], x[i]);
        r[c[i]] = max(r[c[i]], x[i]);
    }
    
    cout << ans << endl;
    return 0;
}