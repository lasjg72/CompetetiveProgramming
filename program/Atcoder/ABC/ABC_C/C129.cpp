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
const ll mod = 1000000007;

vector<ll> dp;

int main()
{
    ll n, m;
    cin >> n >> m;
    vector<ll> a(m+5, 0);
    for(ll i = 0; i < m; i++){
        cin >> a[i];
    }
    dp.resize(n+5, 0);
    dp[0] = 1;
    int j = 0;
    for(ll i = 1; i <= n; i++){
        if(a[j] == i) {
            if(j != m-1) j++;
            if(i != n) continue;
            else break;
        }
        if(i == 1) dp[i] = dp[i-1];
        if(i > 1) dp[i] = (dp[i-1] + dp[i-2]) % mod;
        // cout << "i: " << i << endl;
        // cout << "dp: " << dp[i] << endl;
    }

    cout << dp[n]%mod << endl;
    return 0;
}