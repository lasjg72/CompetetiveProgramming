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

int main()
{
    int n;
    cin >> n;
    vector<ll> c(n);
    for(int i = 0; i < n; i++) cin >> c[i];
    sort(c.begin(), c.end());
    ll ans = c[0], pre = c[0];
    for(int i = 1; i < n; i++){
        ans = ans*(c[i]-i)%mod;
    }
    cout << ans << endl;
    return 0;
}